#include <iostream>
#include <vector>
#include <queue>

#define MAX 32001

using namespace std;

int N, M, InDegree[MAX];
vector<int> P[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    int n1, n2;
    for (int i = 0; i < M; ++i) {
        cin >> n1 >> n2;
        P[n1].push_back(n2);
        InDegree[n2]++;
    }

    vector<int> ret;
    priority_queue<int> q;

    for (int i = 1; i <= N; ++i) {
        if (InDegree[i] == 0)
            q.push(-i);
    }

    while (!q.empty()) {
        auto curr = -q.top();
        q.pop();

        ret.push_back(curr);

        for (int &next: P[curr]) {
            if (--InDegree[next] == 0)
                q.push(-next);
        }
    }

    for (auto &answer: ret)
        cout << answer << ' ';

    return 0;
}