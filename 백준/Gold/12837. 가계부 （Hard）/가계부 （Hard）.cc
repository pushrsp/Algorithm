#include <iostream>
#include <vector>

#define MAX 1000001
#define ll long long

using namespace std;

int N, Q;
ll Arr[MAX], FenWick[MAX * 4];

void Update(int index, int value) {
    while (index < N + 1) {
        FenWick[index] += value;
        index += (index & -index);
    }
}

ll Query(int index) {
    ll ret = 0;
    while (index > 0) {
        ret += FenWick[index];
        index -= (index & -index);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> Q;

    int op, p, q, x;
    for (int i = 0; i < Q; ++i) {
        cin >> op;

        if (op == 1) {
            cin >> p >> x;
            Update(p, x);
        } else {
            cin >> p >> q;
            cout << Query(q) - Query(p - 1) << '\n';
        }
    }

    return 0;
}