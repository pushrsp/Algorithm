#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, E;
int Parent[10001];

int GetParent(int i) {
    if (Parent[i] == i)
        return i;

    return Parent[i] = GetParent(Parent[i]);
}

void UnionParent(int a, int b) {
    a = GetParent(a), b = GetParent(b);
    if (a < b)
        Parent[b] = a;
    else
        Parent[a] = b;
}

bool FindParent(int a, int b) {
    return GetParent(a) == GetParent(b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> V >> E;

    vector<pair<int, pair<int, int>>> Adj;
    int a, b, c;

    for (int i = 0; i < E; ++i) {
        cin >> a >> b >> c;

        Adj.push_back({c, {a, b}});
    }

    sort(Adj.begin(), Adj.end());

    for (int i = 1; i <= V; ++i)
        Parent[i] = i;


    int answer = 0;
    for (auto &adj: Adj) {
        if (!FindParent(adj.second.first, adj.second.second)) {
            answer += adj.first;
            UnionParent(adj.second.first, adj.second.second);
        }
    }

    cout << answer << '\n';
    return 0;
}