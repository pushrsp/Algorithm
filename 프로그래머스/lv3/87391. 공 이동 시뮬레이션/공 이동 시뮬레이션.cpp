#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>

#define ll long long

using namespace std;

ll solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    ll answer = -1;

    int y1 = x, y2 = x;
    int x1 = y, x2 = y;

    for (int i = queries.size() - 1; i >= 0; --i) {
        int cmd = queries[i][0], dist = queries[i][1];

        if (cmd == 0) { //우
            x2 = min(x2 + dist, m - 1);

            if (x1 != 0)
                x1 += dist;

            if (x1 >= m)
                return 0;
        } else if (cmd == 1) {//왼
            x1 = max(x1 - dist, 0);

            if (x2 != m - 1)
                x2 -= dist;

            if (x2 < 0)
                return 0;
        } else if (cmd == 2) { // 아
            y2 = min(y2 + dist, n - 1);

            if (y1 != 0)
                y1 += dist;

            if (y1 >= n)
                return 0;
        } else { //위
            y1 = max(y1 - dist, 0);

            if (y2 != n - 1)
                y2 -= dist;

            if (y2 < 0)
                return 0;
        }
    }

    answer = static_cast<ll>(y2 - y1 + 1) * static_cast<ll>(x2 - x1 + 1);

    return answer;
}