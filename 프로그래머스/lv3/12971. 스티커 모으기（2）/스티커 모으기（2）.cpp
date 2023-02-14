#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <cstring>

#define MAX 100010

using namespace std;

int DP[MAX], N;

int solution(vector<int> sticker) {
    N = static_cast<int>(sticker.size());
    if (N == 1)
        return sticker[0];

    int answer = 0;

    DP[0] = sticker[0], DP[1] = sticker[0];
    for (int i = 2; i < N - 1; ++i)
        DP[i] = max(DP[i - 2] + sticker[i], DP[i - 1]);

    answer = max(answer, DP[N - 2]);

    DP[0] = 0, DP[1] = sticker[1];
    for (int i = 2; i < N; ++i)
        DP[i] = max(DP[i - 2] + sticker[i], DP[i - 1]);

    answer = max(answer, DP[N - 1]);

    return answer;
}