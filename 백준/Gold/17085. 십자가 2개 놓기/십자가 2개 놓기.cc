#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, Map[15][15];

int up(int mid_y, int mid_x) {
    int ret = 0;
    for (int y = mid_y - 1; y >= 0; --y) {
        if (Map[y][mid_x] == 1)
            ret += 1;
        else
            break;
    }

    return ret;
}

int left(int mid_y, int mid_x) {
    int ret = 0;
    for (int x = mid_x - 1; x >= 0; --x) {
        if (Map[mid_y][x] == 1)
            ret += 1;
        else
            break;
    }

    return ret;
}

int down(int mid_y, int mid_x) {
    int ret = 0;
    for (int y = mid_y + 1; y < N; ++y) {
        if (Map[y][mid_x] == 1)
            ret += 1;
        else
            break;
    }

    return ret;
}

int right(int mid_y, int mid_x) {
    int ret = 0;
    for (int x = mid_x + 1; x < M; ++x) {
        if (Map[mid_y][x] == 1)
            ret += 1;
        else
            break;
    }

    return ret;
}

void cover(int len, int mid_y, int mid_x, int num) {
    //위
    for (int y = mid_y; y >= mid_y - len; --y)
        Map[y][mid_x] = num;

    //왼
    for (int x = mid_x; x >= mid_x - len; --x)
        Map[mid_y][x] = num;

    //아
    for (int y = mid_y; y <= mid_y + len; ++y)
        Map[y][mid_x] = num;

    //오
    for (int x = mid_x; x <= mid_x + len; ++x)
        Map[mid_y][x] = num;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    vector<pair<int, int>> points;
    string s;
    for (int y = 0; y < N; ++y) {
        cin >> s;

        for (int x = 0; x < M; ++x) {
            if (s[x] == '#') {
                Map[y][x] = 1;
                points.emplace_back(y, x);
            }
        }
    }

    int ret = 1, dots = 1;
    for (int len = 3; len <= min(N, M); len += 2) {
        for (int i = 0; i < points.size(); ++i) {
            int m1_y = points[i].first, m1_x = points[i].second;

            int u1_len = up(m1_y, m1_x);
            if (u1_len < dots)
                continue;

            int l1_len = left(m1_y, m1_x);
            if (l1_len < dots)
                continue;

            int d1_len = down(m1_y, m1_x);
            if (d1_len < dots)
                continue;

            int r1_len = right(m1_y, m1_x);
            if (r1_len < dots)
                continue;

            cover(dots, m1_y, m1_x, 0);

            int a1 = ((dots) * 4) + 1;
            for (int j = i + 1; j < points.size(); ++j) {
                int m2_y = points[j].first, m2_x = points[j].second;
                if (Map[m2_y][m2_x] != 1)
                    continue;

                int u2_len = up(m2_y, m2_x);
                int l2_len = left(m2_y, m2_x);
                int d2_len = down(m2_y, m2_x);
                int r2_len = right(m2_y, m2_x);

                int offset = min(min(min(u2_len, l2_len), d2_len), r2_len);
                int a2 = (offset * 4) + 1;
                ret = max(ret, a1 * a2);
            }

            cover(dots, m1_y, m1_x, 1);
        }

        dots += 1;
    }

    cout << ret << '\n';

    return 0;
}