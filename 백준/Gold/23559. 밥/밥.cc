#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct Point {
    int a, b, diff;
};

int N, X;
vector<Point> Points;

bool desc_diff(const Point &a, const Point &b) {
    return a.diff > b.diff;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> X;

    Points = vector<Point>(N);
    for (int n = 0; n < N; ++n) {
        cin >> Points[n].a >> Points[n].b;
        Points[n].diff = Points[n].a - Points[n].b;
    }

    sort(Points.begin(), Points.end(), desc_diff);

    int ret = 0;
    for (int i = 0; i < N; ++i) {
        int day = N - i - 1;
        if (Points[i].diff <= 0) {
            ret += Points[i].b;
            X -= 1000;
        } else if (X - 5000 >= day * 1000) {
            ret += Points[i].a;
            X -= 5000;
        } else {
            ret += Points[i].b;
            X -= 1000;
        }
    }

    cout << ret << '\n';

    return 0;
}