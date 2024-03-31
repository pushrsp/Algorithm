#include <cstring>
#include <vector>
#include <cmath>
#include <iostream>
#include <queue>
#include <algorithm>

#define ll long long
#define INF 1e9

using namespace std;

int N, A, B, V[500001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> A >> B;

    queue<vector<int>> q;

    q.push({A, 0, 0});
    q.push({B, 0, 0});

    int ret = -1;
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        int dist = curr[2] == 0 ? 1 : curr[2] * 2;
        int next = curr[0] + dist;
        if (next <= N) {
            if (V[next] == curr[1] + 1) {
                ret = curr[1] + 1;
                break;
            } else {
                V[next] = curr[1] + 1;
                q.push({next, curr[1] + 1, dist});
            }
        }

        next = curr[0] - dist;
        if (next > 0) {
            if (V[next] == curr[1] + 1) {
                ret = curr[1] + 1;
                break;
            } else {
                V[next] = curr[1] + 1;
                q.push({next, curr[1] + 1, dist});
            }
        }
    }

    cout << ret << '\n';

    return 0;
}