#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MAX 16

using namespace std;

int N;
int Price[MAX][MAX];
int DP[1 << MAX][MAX][MAX];

int go(int owner, int visited, int price) {
    int &ret = DP[visited][owner][price];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = 0; i < N; ++i) {
        if (visited & (1 << i))
            continue;
        if (Price[owner][i] < price)
            continue;

        ret = max(ret, go(i, visited | (1 << i), Price[owner][i]) + 1);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    string temp;
    for (int y = 0; y < N; ++y) {
        cin >> temp;

        for (int x = 0; x < temp.length(); ++x)
            Price[y][x] = temp[x] - '0';
    }

    ::memset(DP, -1, sizeof(DP));
    cout << go(0, 1 << 0, 0) + 1 << '\n';
    return 0;
}