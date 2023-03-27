#include <iostream>
#include <algorithm>

#define ll unsigned long long
#define MAX 100001

using namespace std;

int N;
ll M;
ll Arr[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> N >> M;

    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> Arr[i];
        sum += Arr[i];
    }

    sum *= M;

    ll ret = sum;
    ll left = 0, right = sum + 1, mid, cap;
    while (left <= right) {
        mid = (right + left) / 2;
        cap = 0;

        for (int i = 0; i < N; ++i)
            cap += mid / Arr[i];

        if (cap >= M) {
            ret = min(ret, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ret << '\n';
    return 0;
}