#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define ll long long
#define MAX 1000001

using namespace std;

int N, M;
ll SUM[MAX], MOD[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    int num;
    for (int i = 1; i <= N; ++i) {
        cin >> num;

        SUM[i] = (SUM[i - 1] + num) % M;
        MOD[SUM[i]]++;
    }

    ll ret = MOD[0];
    for (int i = 0; i < M; ++i)
        ret += MOD[i] * (MOD[i] - 1) / 2;

    cout << ret << '\n';
    return 0;
}