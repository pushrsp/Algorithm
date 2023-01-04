#include <iostream>
#include <vector>

#define MAX 10001

using namespace std;

int V, E, Visited[MAX], Number;
vector<int> Nodes[MAX];
bool Cut[MAX];

int go(int node, bool is_root) {
    Visited[node] = ++Number;
    int ret = Visited[node];

    int child = 0;
    for (auto &next: Nodes[node]) {
        if (Visited[next]) {
            ret = min(ret, Visited[next]);
            continue;
        }

        child++;
        int prev = go(next, false);

        if (!is_root && prev >= Visited[node])
            Cut[node] = true;

        ret = min(ret, prev);
    }

    if (is_root)
        Cut[node] = child >= 2;

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> V >> E;

    int a, b;
    for (int i = 0; i < E; ++i) {
        cin >> a >> b;

        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }

    for (int i = 1; i <= V; ++i) {
        if (!Visited[i])
            go(i, true);
    }

    int ret = 0;
    vector<int> answer;
    for (int i = 1; i <= V; ++i) {
        if (Cut[i]) {
            ret += 1;
            answer.push_back(i);
        }
    }

    cout << ret << '\n';
    for (int &aa: answer)
        cout << aa << ' ';
    
    return 0;
}