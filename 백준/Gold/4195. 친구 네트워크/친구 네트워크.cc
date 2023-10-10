#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int T, F, Parent[200001], Nums[200001];

int get_idx(map<string, int> &m, string &f, int &start) {
    if (m.find(f) == m.end()) {
        m.insert(make_pair(f, ++start));
        return start;
    }

    return m[f];
}

int get_parent(int i) {
    if (Parent[i] == i)
        return i;

    return Parent[i] = get_parent(Parent[i]);
}

int merge(int a, int b) {
    a = get_parent(a), b = get_parent(b);

    if (a != b) {
        Nums[min(a, b)] += Nums[max(a, b)];
        Nums[max(a, b)] = 0;
    }

    if (a < b)
        return Parent[b] = a;
    else
        return Parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> F;

        for (int i = 0; i < 200001; ++i)
            Parent[i] = i, Nums[i] = 1;

        map<string, int> m;
        int start = 0;
        string f1, f2;
        for (int i = 0; i < F; ++i) {
            cin >> f1 >> f2;

            int i1 = get_idx(m, f1, start);
            int i2 = get_idx(m, f2, start);

            cout << Nums[merge(i1, i2)] << '\n';
        }
    }
    return 0;
}