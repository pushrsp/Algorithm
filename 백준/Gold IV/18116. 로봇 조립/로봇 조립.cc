#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>

#define ll long long

using namespace std;

int N, P[1000001], S[1000001];

int get_parent(int n) {
    if (n == P[n])
        return n;

    return P[n] = get_parent(P[n]);
}

void merge(int a, int b) {
    a = get_parent(a), b = get_parent(b);

    if (a == b)
        return;

    if (a < b) {
        P[b] = a;
        S[a] += S[b];
        S[b] = 0;
    } else {
        P[a] = b;
        S[b] += S[a];
        S[a] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int n = 1; n <= 1000000; ++n)
        P[n] = n, S[n] = 1;

    char cmd;
    int a, b, c;
    for (int n = 0; n < N; ++n) {
        cin >> cmd;

        if (cmd == 'I') {
            cin >> a >> b;
            merge(a, b);
        } else {
            cin >> c;
            cout << S[get_parent(c)] << '\n';
        }
    }

    int temp = 0;

    return 0;
}