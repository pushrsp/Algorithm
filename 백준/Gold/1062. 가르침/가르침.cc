#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, K, answer = 0;
vector<string> vec;
vector<bool> Visited;

int get_count() {
    int sum = 0;
    for (const auto &s: vec) {
        bool success = true;

        for (auto c: s) {
            if (!Visited[c - 'a'])
                success = false;
        }

        if (success)
            sum++;
    }

    return sum;
}

void dfs(int cnt, int idx) {
    if (cnt == K) {
        answer = max(answer, get_count());
        return;
    }

    for (int i = idx; i <= 25; ++i) {
        if (Visited[i])
            continue;

        Visited[i] = true;
        dfs(cnt + 1, i);
        Visited[i] = false;
    }
}

int main() {
    cin >> N >> K;
    vec = vector<string>(N);
    Visited = vector<bool>(26, false);

    for (int i = 0; i < N; ++i) {
        cin >> vec[i];
    }

    if (K < 5) {
        cout << 0 << endl;
        return 0;
    }

//    if (K >= 25) {
//        cout << vec.size() << endl;
//        return 0;
//    }

    Visited['a' - 'a'] = true;
    Visited['n' - 'a'] = true;
    Visited['t' - 'a'] = true;
    Visited['i' - 'a'] = true;
    Visited['c' - 'a'] = true;

    dfs(5, 0);

    cout << answer << endl;
    return 0;
}