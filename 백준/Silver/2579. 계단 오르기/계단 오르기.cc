#include <iostream>
#include <vector>
#include <queue>

#define MAX 301

using namespace std;

int N, Arr[MAX], DP[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> Arr[i];

    DP[1] = Arr[1], DP[2] = Arr[1] + Arr[2], DP[3] = max(Arr[1] + Arr[3], Arr[2] + Arr[3]);
    for (int i = 4; i <= N; ++i)
        DP[i] = max(DP[i - 2] + Arr[i], DP[i - 3] + Arr[i - 1] + Arr[i]);


    cout << DP[N] << '\n';
    return 0;
}