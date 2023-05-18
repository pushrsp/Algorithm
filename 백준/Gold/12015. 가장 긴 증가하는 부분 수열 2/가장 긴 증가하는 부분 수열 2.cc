#include <iostream>
#include <queue>
#include <vector>

#define MAX 1000001

using namespace std;

int N, Arr[MAX], DP[MAX];

int Search(int left, int right, int target) {
    int mid;
    while (left < right) {
        mid = (left + right) / 2;

        if (DP[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }

    return right;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> Arr[i];

    DP[0] = Arr[0];
    int i = 1, j = 0;
    while (i < N) {
        if (DP[j] < Arr[i])
            DP[++j] = Arr[i];
        else
            DP[Search(0, j, Arr[i])] = Arr[i];

        i++;
    }

    cout << j + 1 << '\n';
    return 0;
}