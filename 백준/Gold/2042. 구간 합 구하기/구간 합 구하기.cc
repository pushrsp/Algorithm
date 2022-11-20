#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

#define ll long long

using namespace std;

int N, M, K, A, B, C;
vector<ll> FenTree, Arr;
vector<pair<int, pair<int, ll>>> Command;
ll D;

void Update(int index, ll value) {
    while (index < FenTree.size()) {
        FenTree[index] += value;
        index += (index & -index);
    }
}

ll Sum(int index) {
    ll ret = 0;
    while (index > 0) {
        ret += FenTree[index];
        index -= (index & -index);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    Arr = vector<ll>(N + 1);
    FenTree = vector<ll>(N + 1);

    for (int n = 1; n <= N; ++n) {
        cin >> Arr[n];
        Update(n, Arr[n]);
    }

    M += K;
    while (M--) {
        cin >> A;

        if (A == 1) {
            cin >> B >> D;

            ll diff = D - Arr[B];
            Arr[B] = D;
            Update(B, diff);
        } else {
            cin >> B >> C;
            cout << Sum(C) - Sum(B - 1) << '\n';
        }
    }
    return 0;
}