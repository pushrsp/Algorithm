#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int A = INT32_MAX, N, M;
vector<vector<int>> K[6];
int DP[6][21];

int go(int k, int j) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < j; ++i)
        pq.push(0);

    int ret = 0;
    for (auto &req: K[k]) {
        int a = req[0], b = req[1];
        int curr = pq.top();
        pq.pop();

        if (curr <= a) {
            pq.push(a + b);
        } else {
            ret += curr - a;
            pq.push(curr + b);
        }
    }

    return ret;
}

void go(int k, int remain, int sum) {
    if (remain < 0)
        return;
    if (k == M + 1) {
        if (remain == 0)
            A = min(A, sum);

        return;
    }

    for (int i = 1; i <= N - M + 1; ++i)
        go(k + 1, remain - i, sum + DP[k][i]);
}

int solution(int k, int n, vector<vector<int>> reqs) {
    for (auto &req: reqs)
        K[req[2]].push_back(req);

    M = k;
    N = n;

    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= N - k + 1; ++j) {
            DP[i][j] = go(i, j);
        }
    }

    go(1, N, 0);

    return A;
}