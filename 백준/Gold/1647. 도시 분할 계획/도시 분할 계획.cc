#include <iostream>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

struct Point {
    int a, b, c;
};

int N, M, Parent[100001];
vector<Point> Points;

bool asc(Point &a, Point &b) {
    return a.c < b.c;
}

int get_parent(int n) {
    if (n == Parent[n])
        return n;

    return Parent[n] = get_parent(Parent[n]);
}

void merge(int a, int b) {
    a = get_parent(a), b = get_parent(b);

    if (a == b)
        return;

    if (a < b)
        Parent[b] = a;
    else
        Parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int n = 0; n <= N; ++n)
        Parent[n] = n;

    int a, b, c;
    for (int m = 0; m < M; ++m) {
        cin >> a >> b >> c;
        Points.push_back({a, b, c});
    }

    sort(Points.begin(), Points.end(), asc);

    vector<int> answer;
    for (auto &point: Points) {
        if (get_parent(point.a) != get_parent(point.b)) {
            answer.push_back(point.c);
            merge(point.a, point.b);
        }
    }

    int ret = 0;
    for (int i = 0; i < answer.size() - 1; ++i)
        ret += answer[i];

    cout << ret << '\n';

    return 0;
}