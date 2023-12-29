#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int N, M, Parent[100001];
vector<int> P;

int get_parent(int n) {
    if (n == Parent[n])
        return n;

    return Parent[n] = get_parent(Parent[n]);
}

void merge(int a, int b) {
    a = get_parent(a), b = get_parent(b);

    if (a < b) {
        Parent[b] = a;
        P[a] += P[b];
    } else {
        Parent[a] = b;
        P[b] += P[a];
    }
}

void battle(int a, int b) {
    a = get_parent(a), b = get_parent(b);

    if (P[a] > P[b]) {
        P[a] -= P[b];
        Parent[b] = a;
    } else if (P[a] < P[b]) {
        P[b] -= P[a];
        Parent[a] = b;
    } else {
        Parent[a] = 0, Parent[b] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int n = 0; n <= N; ++n)
        Parent[n] = n;

    P = vector<int>(N + 1);
    for (int n = 1; n <= N; ++n)
        cin >> P[n];

    int o, p, q;
    for (int m = 0; m < M; ++m) {
        cin >> o >> p >> q;

        if (o == 1)
            merge(p, q);
        else
            battle(p, q);
    }

    set<int> s;
    for (int n = 1; n <= N; ++n) {
        int pp = get_parent(n);
        if (pp != 0)
            s.insert(pp);
    }

    vector<int> answer;
    for (auto &i: s)
        answer.push_back(P[i]);

    sort(answer.begin(), answer.end());

    cout << s.size() << '\n';
    for (auto &ans: answer)
        cout << ans << ' ';

    return 0;
}