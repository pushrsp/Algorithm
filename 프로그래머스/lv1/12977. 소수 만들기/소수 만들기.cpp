#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <cmath>

#define MAX 51

using namespace std;

bool Visited[MAX];
int Prime[50001];
vector<int> Nums;

int go(int sum, int n, int count) {
    if (count == 3)
        return Prime[sum] == 0 ? 0 : 1;

    int ret = 0;
    for (int i = n + 1; i < Nums.size(); ++i)
        ret += go(sum + Nums[i], i, count + 1);

    return ret;
}

int solution(vector<int> nums) {
    Nums = nums;
    for (int i = 2; i <= 50000; ++i)
        Prime[i] = i;
    for (int i = 2; i <= ::sqrt(50000); ++i) {
        if (Prime[i] == 0)
            continue;

        for (int j = i * i; j <= 50000; j += i)
            Prime[j] = 0;
    }

    int answer = go(0, -1, 0);

    return answer;
}