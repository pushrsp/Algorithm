#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

int Answer = INT32_MAX, N;
vector<int> Weak, Dist;

void go(int cnt, int pos, int visited) {
    if (cnt > Dist.size())
        return;
    if (cnt >= Answer)
        return;

    for (int i = 0; i < Weak.size(); ++i) {
        int nextPos = (pos + i) % Weak.size();
        int diff = Weak[nextPos] - Weak[pos];
        if (nextPos < pos)
            diff += N;

        if (diff > Dist[Dist.size() - cnt])
            break;

        visited |= (1 << nextPos);
    }

    if (visited == (1 << Weak.size()) - 1) {
        Answer = min(Answer, cnt);
        return;
    }

    for (int i = 0; i < Weak.size(); ++i) {
        if (visited & (1 << i))
            continue;

        go(cnt + 1, i, visited);
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    sort(dist.begin(), dist.end());
    Weak = weak;
    Dist = dist;
    N = n;

    for (int i = 0; i < Weak.size(); ++i)
        go(1, i, 0);

    if (Answer == INT32_MAX)
        return -1;

    return Answer;
}