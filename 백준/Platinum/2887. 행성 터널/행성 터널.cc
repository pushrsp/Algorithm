#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MAX 100001

using namespace std;

int N, Parent[MAX];
vector<pair<int, int>> X, Y, Z;
vector<pair<int, pair<int, int>>> Dist;

int GetParent(int i) {
    if (i == Parent[i])
        return i;

    return Parent[i] = GetParent(Parent[i]);
}

void Union(int a, int b) {
    a = GetParent(a), b = GetParent(b);

    if (a < b)
        Parent[b] = a;
    else
        Parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i)
        Parent[i] = i;

    int x, y, z;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y >> z;

        X.emplace_back(x, i);
        Y.emplace_back(y, i);
        Z.emplace_back(z, i);
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());

    for (int i = 0; i < N - 1; ++i) {
        Dist.emplace_back(::abs(X[i + 1].first - X[i].first), make_pair(X[i].second, X[i + 1].second));
        Dist.emplace_back(::abs(Y[i + 1].first - Y[i].first), make_pair(Y[i].second, Y[i + 1].second));
        Dist.emplace_back(::abs(Z[i + 1].first - Z[i].first), make_pair(Z[i].second, Z[i + 1].second));
    }

    sort(Dist.begin(), Dist.end());

    int ret = 0;
    for (auto &dist: Dist) {
        int a = dist.second.first;
        int b = dist.second.second;
        int d = dist.first;

        if (GetParent(a) != GetParent(b)) {
            Union(a, b);
            ret += d;
        }
    }

    cout << ret << '\n';
    return 0;
}