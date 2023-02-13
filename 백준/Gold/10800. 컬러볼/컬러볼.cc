#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 200001

using namespace std;

struct Ball {
    int index, color, size;

    bool operator<(const Ball &other) const {
//        if (size == other.size)
//            return index < other.index;

        return size < other.size;
    }
};

int N, DP[MAX], Ret[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    vector<Ball> vec;
    int c, s;
    for (int i = 0; i < N; ++i) {
        cin >> c >> s;

        vec.push_back({i, c, s});
    }

    sort(vec.begin(), vec.end());

    int sum = 0, j = 0;
    for (int i = 0; i < N; ++i) {
        while (vec[i].size > vec[j].size) {
            sum += vec[j].size;
            DP[vec[j].color] += vec[j].size;
            j++;
        }

        Ret[vec[i].index] = sum - DP[vec[i].color];
    }

    for (int i = 0; i < N; ++i)
        cout << Ret[i] << '\n';

    return 0;
}