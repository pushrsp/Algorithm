#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <cmath>

#define MAX_SCORE 10

using namespace std;

int N, Score = 0;
vector<int> Info, Temp(11), Answer;

int GetArrowCount(int win, vector<int> &info) {
    int ret = 0;
    for (int i = 0; i < 10; ++i) {
        if (win & (1 << i))
            ret += info[i] + 1;
    }

    return ret;
}

pair<int, int> GetScore(int win, vector<int> &info) {
    int a = 0, l = 0;
    for (int i = 0; i < 10; ++i) {
        if (win & (1 << i)) {
            l += MAX_SCORE - i;
        } else if (info[i] != 0)
            a += MAX_SCORE - i;
    }

    return {a, l};
}

bool cmp_pair(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first)
        return a.second > b.second;

    return a.first > b.first;
}

vector<int> solution(int n, vector<int> info) {
    vector<pair<int, int>> temp;
    int max_diff = 0;
    for (int i = 1; i < (1 << 10); ++i) {
        int arrow = GetArrowCount(i, info);
        if (arrow > n)
            continue;

        pair<int, int> score = GetScore(i, info);
        if (score.second - score.first >= max_diff) {
            max_diff = score.second - score.first;
            temp.emplace_back(max_diff, i);
        }
    }

    if (temp.empty() || max_diff == 0)
        return {-1};

    sort(temp.begin(), temp.end(), cmp_pair);
    vector<int> ret;
    for (int i = 0; i < 10; ++i) {
        if (temp[0].second & (1 << i)) {
            n -= info[i] + 1;
            ret.push_back(info[i] + 1);
        } else {
            ret.push_back(0);
        }
    }

    if (n != 0)
        ret.push_back(n);
    else
        ret.push_back(0);

    return ret;
}