#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, K, answer = 0;
vector<string> vec;
vector<bool> Visited, V;

int get_count(int bit) {
    int sum = 0;
    for (const auto &s: vec) {
        bool success = true;

        for (auto c: s) {
            if (!(bit & (1 << (c - 'a'))))
                success = false;
        }

        if (success)
            sum++;
    }

    return sum;
}

void dfs(int cnt, int idx, int v) {
    if (cnt > K)
        return;

    if (cnt == K) {
        answer = max(answer, get_count(v));
        return;
    }

    for (int i = idx; i <= 25; ++i) {
        if (Visited[i])
            continue;

        int vv = v;
        vv |= (1 << i);

        if (V[i])
            continue;

        V[i] = true;
        Visited[i] = true;
        dfs(cnt + 1, i, vv);
        Visited[i] = false;
        V[i] = false;
    }
}

int main() {
    cin >> N >> K;
    vec = vector<string>(N);
    Visited = vector<bool>(26, false);
    V = vector<bool>(67108865, false);

    for (int i = 0; i < N; ++i) {
        cin >> vec[i];
    }

    if (K < 5) {
        cout << 0 << endl;
        return 0;
    }

    Visited['a' - 'a'] = true;
    Visited['n' - 'a'] = true;
    Visited['t' - 'a'] = true;
    Visited['i' - 'a'] = true;
    Visited['c' - 'a'] = true;

    int v = 0;
    v |= (1 << ('a' - 'a'));
    v |= (1 << ('n' - 'a'));
    v |= (1 << ('t' - 'a'));
    v |= (1 << ('i' - 'a'));
    v |= (1 << ('c' - 'a'));

    dfs(5, 0, v);

    cout << answer << endl;
    return 0;
}