#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int N, K;

int get_bottle(int n) {
    int ret = 0;
    while (n > 0) {
        if (n % 2)
            ret += 1;

        n /= 2;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    if (N <= K) {
        cout << 0 << '\n';
    } else {
        int ans = 0;
        while (true) {
            int bottle = get_bottle(N);
            if (bottle <= K)
                break;

            ans++;
            N++;
        }

        cout << ans << '\n';
    }
    return 0;
}