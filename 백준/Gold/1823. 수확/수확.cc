#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

#define MAX 2001

using namespace std;

int N, Arr[MAX], DP[MAX][MAX];

int go(int left, int right, int count) {
    if (left > right)
        return 0;

    int &ret = DP[left][right];
    if (ret != -1)
        return ret;

    ret = max(go(left + 1, right, count + 1) + Arr[left] * count, go(left, right - 1, count + 1) + Arr[right] * count);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> Arr[i];

    ::memset(DP, -1, sizeof(DP));

    cout << go(1, N, 1) << '\n';
    
    return 0;
}