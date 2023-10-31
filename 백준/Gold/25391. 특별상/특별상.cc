#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

#define ll long long

using namespace std;

struct H {
    ll a, b;
    bool used;
};

int N, M, K;

bool cmp1(const H &a, const H &b) {
    if (a.b == b.b)
        return a.a > b.a;

    return a.b > b.b;
}

bool cmp2(const H &a, const H &b) {
    if (a.a == b.a)
        return a.b > b.b;

    return a.a > b.a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> K;

    vector<H> vec(N);
    for (int n = 0; n < N; ++n) {
        cin >> vec[n].a >> vec[n].b;
        vec[n].used = false;
    }

    sort(vec.begin(), vec.end(), cmp1);

    for (int k = 0; k < K; ++k)
        vec[k].used = true;

    sort(vec.begin(), vec.end(), cmp2);

    for (int i = 0; M > 0; i++) {
        if (!vec[i].used) {
            vec[i].used = true;
            M--;
        }
    }

    ll ret = 0;
    for (auto &v: vec) {
        if (v.used)
            ret += v.a;
    }

    cout << ret << '\n';

    return 0;
}