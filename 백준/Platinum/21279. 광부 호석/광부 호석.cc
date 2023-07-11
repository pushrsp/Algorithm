#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int x, y, v, c;
};

int N, C;
vector<Point> Points, SegValue;
vector<int> SegHeight, SegWidth;

bool cmp_point(const Point &a, const Point &b) {
    return a.x < b.x;
}

int MakeSegHeight(int node, int start, int end) {
    if (start == end)
        return SegHeight[start] = Points[start].y;

    int mid = (start + end) / 2;
    return SegHeight[node] = max(MakeSegHeight(2 * node, start, mid), MakeSegHeight(2 * node + 1, mid + 1, end));
}

int MakeSegWidth(int node, int start, int end) {
    if (start == end)
        return SegWidth[start] = Points[start].x;

    int mid = (start + end) / 2;
    return SegWidth[node] = max(MakeSegWidth(2 * node, start, mid), MakeSegWidth(2 * node + 1, mid + 1, end));
}

Point MakeSegValue(int node, int start, int end) {
    if (start == end)
        return SegValue[node] = {Points[start].x, Points[start].y, Points[start].v, 1};

    int mid = (start + end) / 2;
    Point l = MakeSegValue(2 * node, start, mid);
    Point r = MakeSegValue(2 * node + 1, mid + 1, end);

    return SegValue[node] = {min(l.x, r.x), min(l.y, r.y), l.v + r.v, l.c + r.c};
}

int QueryHeight(int node, int start, int end, int left, int right) {
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return SegHeight[node];

    int mid = (start + end) / 2;
    int l = QueryHeight(2 * node, start, mid, left, right);
    int r = QueryHeight(2 * node + 1, mid + 1, end, left, right);

    return max(l, r);
}

int QueryWidth(int node, int start, int end, int left, int right) {
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return SegWidth[node];

    int mid = (start + end) / 2;
    int l = QueryWidth(2 * node, start, mid, left, right);
    int r = QueryWidth(2 * node + 1, mid + 1, end, left, right);

    return max(l, r);
}

Point QueryValue(int node, int start, int end, int left, int right, int height, int width) {
    if (left > end || right < start)
        return {0, 0};
    if (left <= start && end <= right) {
        if (SegValue[node].x > width || SegValue[node].y > height)
            return {0, 0, 0, 0};

        return SegValue[node];
    }

    int mid = (start + end) / 2;
    Point l = QueryValue(2 * node, start, mid, left, right, height, width);
    Point r = QueryValue(2 * node + 1, mid + 1, end, left, right, height, width);

    return {max(l.x, r.x), max(l.y, r.y), l.v + r.v, l.c + r.c};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> C;

    Points = vector<Point>(N);
    for (int n = 0; n < N; ++n)
        cin >> Points[n].x >> Points[n].y >> Points[n].v;

    int h = static_cast<int>(::ceil(::log2(N)));
    SegHeight.resize(1 << (h + 1));
    SegWidth.resize(1 << (h + 1));
    SegValue.resize(1 << (h + 1));

    MakeSegHeight(1, 0, N - 1);
    MakeSegWidth(1, 0, N - 1);
    MakeSegValue(1, 0, N - 1);

    sort(Points.begin(), Points.end(), cmp_point);

    int ret = 0, left = 0, right = N - 1;
    while (left < right) {
        int max_height = QueryHeight(1, 0, N - 1, left, right);
        int max_width = QueryWidth(1, 0, N - 1, left, right);
        Point result = QueryValue(1, 0, N - 1, left, right, max_height, max_width);

        if (result.c > C) {
            right--;
        } else {
            ret = max(ret, result.v);
            left++;
        }
    }

    cout << ret << '\n';

    return 0;
}