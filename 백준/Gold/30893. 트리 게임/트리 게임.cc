#include <iostream>
#include <queue>
#include <set>

#define INF 987654321

using namespace std;

int N, S, E;
vector<int> Adj[100001], History, Temp;
bool Success, Visited[100001];

void go(int n) {
    if (n == E) {
        Success = true;

        for (int &node: Temp)
            History.push_back(node);

        return;
    }

    Visited[n] = true;
    for (auto &next: Adj[n]) {
        if (Visited[next])
            continue;
        if (Success)
            return;

        Temp.push_back(next);
        go(next);
        Temp.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> S >> E;

    int a, b;
    for (int n = 0; n < N - 1; ++n) {
        cin >> a >> b;

        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }

    Temp.push_back(S);
    go(S);

    set<int> s;
    for (auto &h: History)
        s.insert(h);

    for (int i = 1; i < History.size() - 1; i += 2) {
        for (auto &node: Adj[History[i]]) {
            if (s.find(node) == s.end()) {
                cout << "Second" << '\n';
                return 0;
            }
        }
    }

    cout << "First" << '\n';

    return 0;
}