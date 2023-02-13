#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 50001

using namespace std;

int N, Arr[MAX], T, DP[4][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int sum = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> Arr[i];
        Arr[i] += Arr[i - 1];
    }

    cin >> T;

    for (int i = 1; i <= 3; ++i) { // 소형 객차 종류
        for (int j = i * T; j <= N; ++j) {
            int t1 = DP[i][j - 1]; // 현재 객차를 선택하지 않은 경우
            int t2 = DP[i - 1][j - T] + Arr[j] - Arr[j - T]; //현재 객차를 선택할 경우
            DP[i][j] = max(t1, t2);
        }
    }

    cout << DP[3][N] << '\n';
    return 0;
}