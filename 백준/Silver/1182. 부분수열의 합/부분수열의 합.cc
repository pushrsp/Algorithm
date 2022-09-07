#include <iostream>
#include <vector>

using namespace std;

int N, S, ANSWER = 0;
vector<int> vec;
vector<bool> visited;

void dfs(int cnt, int idx, int sum) {
    if (cnt > 0 && sum == S)
        ANSWER++;

    if (cnt >= N)
        return;

    for (int i = idx; i < N; ++i) {
        if (visited[i])
            continue;

        visited[i] = true;
        dfs(cnt + 1, i, sum + vec[i]);
        visited[i] = false;
    }
}

int main() {
    cin >> N >> S;

    vec = vector<int>(N);
    visited = vector<bool>(N, false);
    for (int n = 0; n < N; ++n)
        cin >> vec[n];

    dfs(0, 0, 0);
    cout << ANSWER << endl;
    return 0;
}