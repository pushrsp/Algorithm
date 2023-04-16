#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MAX 1001

using namespace std;

int N, M, K;
vector<char> Cards;
vector<pair<int, char>> Adj[501];
int DP[MAX][MAX];

int go(int curr, int n) {
    if (n == N)
        return 0;

    int &ret = DP[curr][n];
    if (ret != -1)
        return ret;

    ret = 0;
    for (auto &next: Adj[curr]) {
        int sum = go(next.first, n + 1);
        if (next.second == Cards[n])
            sum += 10;

        ret = max(ret, sum);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    Cards = vector<char>(N);
    for (int i = 0; i < N; ++i)
        cin >> Cards[i];

    cin >> M >> K;

    int x, y;
    char c;

    for (int i = 0; i < K; ++i) {
        cin >> x >> y >> c;

        Adj[x].emplace_back(y, c);
        Adj[y].emplace_back(x, c);
    }

    ::memset(DP, -1, sizeof(DP));

    cout << go(1, 0) << '\n';

    return 0;
}