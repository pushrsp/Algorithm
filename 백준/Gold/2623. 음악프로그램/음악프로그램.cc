#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int N, M, InDegree[1001];
vector<int> Adj[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    int num;
    for (int m = 0; m < M; ++m) {
        cin >> num;

        vector<int> temp(num);
        for (int n = 0; n < num; ++n)
            cin >> temp[n];

        for (int i = 0; i < temp.size(); ++i) {
            for (int j = i + 1; j < temp.size(); ++j) {
                Adj[temp[i]].push_back(temp[j]);
                InDegree[temp[j]]++;
            }
        }
    }

    queue<int> q;
    for (int n = 1; n <= N; ++n) {
        if (InDegree[n] == 0)
            q.push(n);
    }

    vector<int> ret;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        ret.push_back(curr);

        for (auto &next: Adj[curr]) {
            if (--InDegree[next] == 0)
                q.push(next);
        }
    }

    if (ret.size() != N) {
        cout << 0 << '\n';
    } else {
        for (auto &r: ret)
            cout << r << '\n';
    }
    return 0;
}