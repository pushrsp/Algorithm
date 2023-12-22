#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, Parent[1000001];

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

    for (int n = 0; n <= N; ++n)
        Parent[n] = n;

    bool success = false;
    int a, b, ret = 0;
    for (int m = 0; m < M; ++m) {
        cin >> a >> b;

        if (get_parent(a) == get_parent(b)) {
            if (!success) {
                success = true;
                ret = m + 1;
            }
        } else {
            merge(a, b);
        }
    }

    cout << ret << '\n';

    return 0;
}