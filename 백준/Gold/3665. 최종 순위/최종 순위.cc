#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

#define MAX 501

using namespace std;

int T, N, M, InDegree[MAX], Rank[MAX];
bool Adj[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--) {
        ::memset(InDegree, 0, sizeof(InDegree));
        ::memset(Rank, 0, sizeof(Rank));
        ::memset(Adj, false, sizeof(Adj));

        cin >> N;

        vector<int> vec(N);
        for (int i = 0; i < N; ++i) {
            cin >> vec[i];
            Rank[vec[i]] = i + 1;
        }

        for (int i = 0; i < vec.size(); ++i) {
            for (int j = i + 1; j < vec.size(); ++j) {
                Adj[vec[i]][vec[j]] = true;
                InDegree[vec[j]] += 1;
            }
        }

        cin >> M;

        int a, b;
        for (int i = 0; i < M; ++i) {
            cin >> a >> b;

            if (Rank[a] > Rank[b])
                swap(a, b);

            Adj[a][b] = false;
            InDegree[b]--;

            Adj[b][a] = true;
            InDegree[a]++;
        }

        queue<int> q;
        for (int i = 1; i <= N; ++i) {
            if (InDegree[i] == 0)
                q.push(i);
        }

        if (q.size() > 1) {
            cout << '?' << '\n';
            continue;
        }

        vector<int> answer;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            answer.push_back(cur);

            for (int i = 1; i <= N; ++i) {
                if (Adj[cur][i]) {
                    if (--InDegree[i] == 0)
                        q.push(i);
                }
            }
        }

        if (answer.size() != N) {
            cout << "IMPOSSIBLE" << '\n';
        } else {
            for (auto &ans: answer)
                cout << ans << ' ';
            cout << '\n';
        }
    }
    return 0;
}