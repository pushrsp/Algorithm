#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define ll long long

using namespace std;

int N, M, K, T, A, B, Parent[51], Party[51][51], Size[51];

int get_parent(int i) {
    if (Parent[i] == i)
        return i;

    return Parent[i] = get_parent(Parent[i]);
}

void merge(int a, int b) {
    a = get_parent(a), b = get_parent(b);

    if (a != b) {
        if (a < b)
            Parent[b] = a;
        else
            Parent[a] = b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i <= N; ++i)
        Parent[i] = i;

    cin >> K;
    for (int k = 0; k < K; ++k) {
        cin >> T;
        Parent[T] = 0;
    }

    for (int m = 0; m < M; ++m) {
        cin >> A;
        cin >> B;

        Size[m] = A;
        Party[m][0] = B;

        for (int a = 1; a < A; ++a) {
            cin >> B;
            Party[m][a] = B;
            merge(Party[m][0], Party[m][a]);
        }
    }

    int ret = M;
    for (int m = 0; m < M; ++m) {
        for (int i = 0; i < Size[m]; ++i) {
            if (get_parent(Party[m][i]) == 0) {
                ret--;
                break;
            }
        }
    }

    cout << ret << '\n';

    return 0;
}