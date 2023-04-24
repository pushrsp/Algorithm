#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX 11
#define ll long long

using namespace std;

int N, Arr[6];
int Sum;
ll DP[MAX][MAX][MAX][MAX][MAX][6][6];

ll go(int sum, int prev, int curr) {
    if (sum == Sum)
        return 1;

    ll &ret = DP[Arr[1]][Arr[2]][Arr[3]][Arr[4]][Arr[5]][prev][curr];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = 1; i <= N; ++i) {
        if (prev != i && curr != i && Arr[i] > 0) {
            Arr[i]--;
            ret += go(sum + 1, curr, i);
            Arr[i]++;
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> Arr[i];
        Sum += Arr[i];
    }

    ::memset(DP, -1, sizeof(DP));
    cout << go(0, 0, 0) << '\n';
    return 0;
}