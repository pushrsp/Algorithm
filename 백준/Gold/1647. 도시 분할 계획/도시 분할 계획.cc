#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, Parent[100001];

struct Point {
    int a, b, c;
};

bool asc(const Point &a, const Point &b) {
    return a.c < b.c;
}

int get_parent(int n) {
    if (n == Parent[n])
        return n;

    return Parent[n] = get_parent(Parent[n]);
}

void merge(int a, int b) {
    a = get_parent(a), b = get_parent(b);

    if (a < b)
        Parent[b] = a;
    else
        Parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int n = 1; n <= N; ++n)
        Parent[n] = n;

    vector<Point> points(M);
    for (int m = 0; m < M; ++m)
        cin >> points[m].a >> points[m].b >> points[m].c;


    sort(points.begin(), points.end(), asc);

    vector<int> temp;
    for (auto &p: points) {
        int a = p.a, b = p.b, c = p.c;

        if (get_parent(a) != get_parent(b)) {
            merge(a, b);
            temp.push_back(c);
        }
    }

    int ret = 0;
    for (int i = 0; i < temp.size() - 1; ++i)
        ret += temp[i];

    cout << ret << '\n';

    return 0;
}