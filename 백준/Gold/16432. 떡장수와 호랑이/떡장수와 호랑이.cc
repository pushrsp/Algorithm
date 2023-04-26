#include <iostream>
#include <vector>

#define MAX 2001

using namespace std;

int N;
bool Visited[MAX][10];
vector<int> Temp;
vector<int> D[MAX];

void go(int n, int prev) {
    if (n == N + 1) {
        for (auto &answer: Temp)
            cout << answer << '\n';

        exit(0);
    }

    for (auto &d: D[n]) {
        if (d == prev)
            continue;
        if (Visited[n + 1][d])
            continue;

        Visited[n + 1][d] = true;
        Temp.push_back(d);

        go(n + 1, d);

        Temp.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int m, a;
    for (int i = 1; i <= N; ++i) {
        cin >> m;

        for (int j = 0; j < m; ++j) {
            cin >> a;
            D[i].push_back(a);
        }
    }

    go(1, 0);

    cout << -1 << '\n';
    return 0;
}