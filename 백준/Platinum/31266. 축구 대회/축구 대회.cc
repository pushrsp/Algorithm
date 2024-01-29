#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define ll long long

using namespace std;

struct P {
    int i, a, b, c, d;
};

struct A {
    int i, a, b, c, d;

    bool operator<(const A &other) const {
        return a < other.a;
    }
};

struct M {
    int i, a, b, c, d;

    bool operator<(const M &other) const {
        return b < other.b;
    }
};

struct D {
    int i, a, b, c, d;

    bool operator<(const D &other) const {
        return c < other.c;
    }
};

struct G {
    int i, a, b, c, d;

    bool operator<(const G &other) const {
        return d < other.d;
    }
};

int N;
bool Visited[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    priority_queue<A> a;
    priority_queue<M> m;
    priority_queue<D> d;
    priority_queue<G> g;

    vector<P> vec(N);
    for (int n = 0; n < N; ++n) {
        cin >> vec[n].a >> vec[n].b >> vec[n].c >> vec[n].d;

        a.push({n, vec[n].a, vec[n].b, vec[n].c, vec[n].d});
        m.push({n, vec[n].a, vec[n].b, vec[n].c, vec[n].d});
        d.push({n, vec[n].a, vec[n].b, vec[n].c, vec[n].d});
        g.push({n, vec[n].a, vec[n].b, vec[n].c, vec[n].d});
    }

    ll ret = g.top().d;
    Visited[g.top().i] = true;

    //공격수
    while (!a.empty() && Visited[a.top().i])
        a.pop();

    ret += a.top().a;
    Visited[a.top().i] = true;

    //미드필드
    while (!m.empty() && Visited[m.top().i])
        m.pop();

    ret += m.top().b;
    Visited[m.top().i] = true;

    //수비수
    while (!d.empty() && Visited[d.top().i])
        d.pop();

    ret += d.top().c;
    Visited[d.top().i] = true;

    for (int n = 0; n < N; ++n) {
        if (Visited[n])
            continue;

        ret += max(max(vec[n].a, vec[n].b), vec[n].c);
    }

    cout << ret << '\n';

    return 0;
}