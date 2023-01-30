#include <string>
#include <vector>
#include <iostream>
#include <queue>

#define INF 987654321
#define MAX 1000001

using namespace std;

int DP[MAX];

int solution(int x, int y, int n) {
    fill(DP, DP + MAX, INF);
    DP[x] = 0;
    for (int i = x; i < y; ++i) {
        if (DP[i] == INF)
            continue;

        if (i + n <= y)
            DP[i + n] = min(DP[i + n], DP[i] + 1);
        if (i * 2 <= y)
            DP[i * 2] = min(DP[i * 2], DP[i] + 1);
        if (i * 3 <= y)
            DP[i * 3] = min(DP[i * 3], DP[i] + 1);
    }

    if (DP[y] == INF)
        return -1;

    return DP[y];
}