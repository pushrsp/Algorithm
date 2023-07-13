#include <iostream>
#include <vector>

using namespace std;

int N, Arr[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int sum = 0, sum2 = 0;
    for (int n = 1; n <= N; ++n) {
        cin >> Arr[n];
        sum2 += Arr[n] / 2;
        sum += Arr[n];
    }

    if (sum % 3 != 0) {
        cout << "NO" << '\n';
    } else {
        sum /= 3;

        if (sum2 >= sum)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}