#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct B {
    int a, b, c;
};

int N, K, Ret;
vector<B> Vec;
bool Visited[11];

void go(int n, int sum, vector<B> &history) {
    if (n == N + 1) {
        Ret = max(Ret, sum);
        return;
    }

    for (int i = 1; i <= N; ++i) {
        if (Visited[i])
            continue;

        Visited[i] = true;
        B prev = history[n - 1];
        history.push_back(Vec[i]);

        int k = prev.c * history.back().c;
        if (k <= K)
            go(n + 1, sum + (prev.a * history.back().b), history);

        history.pop_back();
        Visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    Vec = vector<B>(N + 1);
    for (int n = 1; n <= N; ++n)
        cin >> Vec[n].a;
    for (int n = 1; n <= N; ++n)
        cin >> Vec[n].b;
    for (int n = 1; n <= N; ++n)
        cin >> Vec[n].c;

    vector<B> history;
    history.push_back({0, 0, 0});
    go(1, 0, history);

    if (Ret == 0)
        cout << -1 << '\n';
    else
        cout << Ret << '\n';

    return 0;
}