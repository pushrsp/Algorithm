#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>

#define ll long long

using namespace std;
vector<int> Seg, Stones;

int InitSeg(int node, int start, int end) {
    if (start == end)
        return Seg[node] = Stones[start];

    int mid = (start + end) / 2;
    return Seg[node] = max(InitSeg(2 * node, start, mid), InitSeg(2 * node + 1, mid + 1, end));
}

int Query(int node, int from, int to, int left, int right) {
    if (to < left || right < from)
        return -1;
    if (left <= from && to <= right)
        return Seg[node];

    int mid = (from + to) / 2;
    return max(Query(2 * node, from, mid, left, right), Query(2 * node + 1, mid + 1, to, left, right));
}

int solution(vector<int> stones, int k) {
    Stones = stones;
    int answer = INT32_MAX;

    Seg = vector<int>(1 << (static_cast<int>(::ceil(::log2(Stones.size())) + 1)));
    InitSeg(1, 0, Stones.size() - 1);

    for (int i = 0; i <= stones.size() - k; ++i)
        answer = min(answer, Query(1, 0, Stones.size() - 1, i, i + k - 1));

    if (answer == INT32_MAX)
        return 0;

    return answer;
}