#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX 500001
#define ll long long

using namespace std;

int N, Arr[MAX], DP[MAX];
ll Ret;

void merge(int left, int right) {
    int mid = (left + right) / 2;
    int cnt = 0, i = left, j = mid + 1, start = left;

    while (i <= mid && j <= right) {
        if (Arr[i] <= Arr[j]) {
            DP[start] = Arr[i];
            i++, start++;
            Ret += cnt;
        } else {
            DP[start] = Arr[j];
            cnt++, j++, start++;
        }
    }

    for (int k = i; k <= mid; ++k) {
        DP[start] = Arr[k];
        start++;
        Ret += cnt;
    }

    for (int k = j; k <= right; ++k) {
        DP[start] = Arr[k];
        start++;
    }

    for (int k = left; k <= right; ++k)
        Arr[k] = DP[k];
}

void go(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        go(left, mid), go(mid + 1, right);
        merge(left, right);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> Arr[i];

    go(0, N - 1);
    cout << Ret << '\n';
    return 0;
}