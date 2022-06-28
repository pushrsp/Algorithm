#include <iostream>
#include <queue>

using namespace std;

int T;

int main() {
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int N, M;
        cin >> N >> M;

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for (int j = 0; j < N; ++j) {
            int p;
            cin >> p;
            q.push({j, p});
            pq.push(p);
        }

        int cnt = 0;
        while (!q.empty()) {
            auto now = q.front();
            q.pop();

            if (pq.top() == now.second) {
                pq.pop();
                cnt++;

                if (now.first == M) {
                    cout << cnt << endl;
                    break;
                }
            } else
                q.push(now);
        }
    }
    return 0;
}