#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N, M;
vector<int> Friends[1001], Enemies[1001];
bool Visited[1001];

void go(int node) {
    Visited[node] = true;

    for (int &f: Friends[node]) {
        if (Visited[f])
            continue;

        go(f);
    }

    for (int &e: Enemies[node]) {
        for (int &ee: Enemies[e]) {
            if (Visited[ee])
                continue;

            go(ee);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    cin >> M;

    for (int i = 0; i < M; ++i) {
        char c;
        int a, b;

        cin >> c >> a >> b;

        if (c == 'E')
            Enemies[a].push_back(b), Enemies[b].push_back(a);
        else
            Friends[a].push_back(b), Friends[b].push_back(a);
    }

    int ret = 0;
    for (int i = 1; i <= N; ++i) {
        if (!Visited[i]) {
            go(i);
            ret++;
        }
    }

    cout << ret << '\n';

    return 0;
}