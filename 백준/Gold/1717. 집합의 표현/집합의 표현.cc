#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, Parent[1000001];

int GetParent(int n) {
    if (Parent[n] == n)
        return n;

    return Parent[n] = GetParent(Parent[n]);
}

void UnionParent(int a, int b) {
    a = GetParent(a), b = GetParent(b);

    if (a < b)
        Parent[b] = a;
    else
        Parent[a] = b;
}

bool FindParent(int a, int b) {
    return GetParent(a) == GetParent(b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
        Parent[i] = i;

    int cmd, n1, n2;
    for (int i = 0; i < M; ++i) {
        cin >> cmd >> n1 >> n2;

        if (cmd) {
            if (FindParent(n1, n2))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        } else {
            UnionParent(n1, n2);
        }
    }

    return 0;
}