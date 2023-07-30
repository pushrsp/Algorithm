#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct Road {
    int a, b, dist;
};

int N, M, P1[1001], P2[1001];
vector<Road> R1, R2;

bool cmp_road1(const Road &a, const Road &b) {
    return a.dist < b.dist;
}

bool cmp_road2(const Road &a, const Road &b) {
    return a.dist > b.dist;
}

int get_p1(int n) {
    if (P1[n] == n)
        return n;

    return P1[n] = get_p1(P1[n]);
}

int get_p2(int n) {
    if (P2[n] == n)
        return n;

    return P2[n] = get_p2(P2[n]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int n = 0; n <= N; ++n) {
        P1[n] = n;
        P2[n] = n;
    }

    int a, b, c;
    for (int m = 0; m < M + 1; ++m) {
        cin >> a >> b >> c;

        R1.push_back({a, b, c});
        R2.push_back({a, b, c});
    }

    sort(R1.begin(), R1.end(), cmp_road1);
    sort(R2.begin(), R2.end(), cmp_road2);

    int mx = 0, mn = 0;
    for (int m = 0; m < M + 1; ++m) {
        int mx_a = get_p1(R1[m].a);
        int mx_b = get_p1(R1[m].b);

        int mn_a = get_p2(R2[m].a);
        int mn_b = get_p2(R2[m].b);

        if (mx_a != mx_b) {
            if (mx_a < mx_b)
                P1[mx_b] = mx_a;
            else
                P1[mx_a] = mx_b;

            if (R1[m].dist == 0)
                mx += 1;
        }

        if (mn_a != mn_b) {
            if (mn_a < mn_b)
                P2[mn_b] = mn_a;
            else
                P2[mn_a] = mn_b;

            if (R2[m].dist == 0)
                mn += 1;
        }
    }

    mx *= mx;
    mn *= mn;

    cout << mx - mn << '\n';

    return 0;
}