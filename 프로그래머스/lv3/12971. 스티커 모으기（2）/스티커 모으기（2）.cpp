#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <cstring>

#define MAX 100010

using namespace std;

int DP[MAX], N, Arr[MAX];

int go(int i) {
    if (i > N)
        return 0;

    int &ret = DP[i];
    if (ret != -1)
        return ret;

    return ret = max(go(i + 2) + Arr[i], go(i + 1));
}

int solution(vector<int> sticker) {
    N = static_cast<int>(sticker.size()) - 1;
    for (int i = 0; i <= N; ++i)
        Arr[i] = sticker[i];

    ::memset(DP, -1, sizeof(DP));

    int answer = go(1);

    ::memset(DP, -1, sizeof(DP));
    N = static_cast<int>(sticker.size()) - 2;

    answer = max(answer, go(2) + Arr[0]);
    return answer;
}