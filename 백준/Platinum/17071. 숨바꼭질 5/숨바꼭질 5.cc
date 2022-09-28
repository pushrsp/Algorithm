#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;
int Visited[2][500001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    if (N == K) {
        cout << '0' << '\n';
        return 0;
    }

    queue<int> q;

    Visited[0][N] = 1;
    q.push(N);

    bool success = false;
    int cnt = 1;
    while (!q.empty()) {
        K += cnt;

        if (K > 500000)
            break;

        if (Visited[cnt % 2][K]) {
            success = true;
            break;
        }

        int q_size = q.size();
        for (int i = 0; i < q_size; ++i) {
            int x = q.front();
            q.pop();

            for (int next: {x + 1, x - 1, x * 2}) {
                if (next < 0 || next > 500000)
                    continue;
                if (Visited[cnt % 2][next])
                    continue;

                if (next == K) {
                    success = true;
                    break;
                }

                Visited[cnt % 2][next] = 1;
                q.push(next);
            }

            if (success)
                break;
        }

        if (success)
            break;

        cnt++;
    }

    if (success)
        cout << cnt << '\n';
    else
        cout << -1 << '\n';
    return 0;
}