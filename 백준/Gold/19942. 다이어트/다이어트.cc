#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Food {
    int protein, fat, carbon, vitamin, price;
};
int N, MinP, MinF, MinC, MinV;
vector<Food> Vec;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> MinP >> MinF >> MinC >> MinV;

    Vec = vector<Food>(N);
    for (int i = 0; i < N; ++i)
        cin >> Vec[i].protein >> Vec[i].fat >> Vec[i].carbon >> Vec[i].vitamin >> Vec[i].price;

    int p = 0, f = 0, c = 0, v = 0, price = 0;
    vector<pair<int, vector<int>>> answer;
    for (int i = 0; i < (1 << N); ++i) {
        vector<int> temp;
        for (int j = 0; j < Vec.size(); ++j) {
            if (i & (1 << j)) {
                p += Vec[j].protein;
                f += Vec[j].fat;
                c += Vec[j].carbon;
                v += Vec[j].vitamin;
                price += Vec[j].price;

                temp.push_back(j + 1);
            }
        }

        if (p >= MinP && f >= MinF && c >= MinC && v >= MinV)
            answer.emplace_back(price, temp);

        p = 0;
        f = 0;
        c = 0;
        v = 0;
        price = 0;
    }

    if (answer.empty()) {
        cout << -1 << '\n';
        return 0;
    }

    sort(answer.begin(), answer.end());
    cout << answer[0].first << '\n';
    for (int gradient: answer[0].second)
        cout << gradient << ' ';

    return 0;
}