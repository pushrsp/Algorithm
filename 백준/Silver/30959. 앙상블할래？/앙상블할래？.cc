#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    int cmp[M];
    for (int m = 0; m < M; ++m)
        cin >> cmp[m];

    int highest = 0;
    vector<vector<int>> en(N, vector<int>(M));
    for (int n = 0; n < N; ++n) {
        int cnt = 0;
        for (int m = 0; m < M; ++m) {
            cin >> en[n][m];

            if (cmp[m] == en[n][m])
                cnt += 1;
        }

        highest = max(highest, cnt);
    }

    for (int i = 0; i <= (1 << N); ++i) {
        vector<int> temp;
        for (int n = 0; n < N; ++n) {
            if (i & (1 << n))
                temp.push_back(n);
        }

        if (temp.size() % 2 == 0)
            continue;

        vector<int> answer(M);
        for (int m = 0; m < M; ++m) {
            int zero = 0, one = 0;

            for (auto &idx: temp) {
                if (en[idx][m])
                    one += 1;
                else
                    zero += 1;
            }

            if (zero > one)
                answer[m] = 0;
            else
                answer[m] = 1;
        }

        int cnt = 0;
        for (int m = 0; m < M; ++m) {
            if (cmp[m] == answer[m])
                cnt += 1;
        }

        if (cnt > highest) {
            cout << 1 << '\n';
            return 0;
        }
    }

    cout << 0 << '\n';
    
    return 0;
}