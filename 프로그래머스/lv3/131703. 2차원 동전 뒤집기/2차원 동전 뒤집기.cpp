#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>

#define INF 987654321

using namespace std;

int MaxY, MaxX;

bool CheckSame(vector<vector<int>> &a, vector<vector<int>> &b) {
    for (int y = 0; y < MaxY; ++y) {
        for (int x = 0; x < MaxX; ++x) {
            if (a[y][x] != b[y][x])
                return false;
        }
    }

    return true;
}

int GetBit(int n) {
    if (n == 0)
        return 0;

    return n % 2 + GetBit(n / 2);
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = INF;

    MaxY = static_cast<int>(beginning.size()), MaxX = static_cast<int>(beginning[0].size());
    for (int i = 0; i < (1 << MaxY); ++i) {
        vector<vector<int>> t1(beginning);

        for (int y = 0; y < MaxY; ++y) {
            if (i & (1 << y)) {
                for (int x = 0; x < MaxX; ++x)
                    t1[y][x] = !t1[y][x];
            }
        }

        for (int j = 0; j < (1 << MaxX); ++j) {
            vector<vector<int>> t2(t1);

            for (int x = 0; x < MaxX; ++x) {
                if (j & (1 << x)) {
                    for (int y = 0; y < MaxY; ++y)
                        t2[y][x] = !t2[y][x];
                }

                if (CheckSame(t2, target))
                    answer = min(answer, GetBit(i) + GetBit(j));
            }
        }
    }
    
    return answer == INF ? -1 : answer;
}