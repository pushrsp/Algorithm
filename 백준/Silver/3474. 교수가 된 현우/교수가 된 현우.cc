#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int cnt1 = 0, cnt2 = 0;
        for (int i = 2; i <= n; i *= 2)
            cnt1 += n / i;
        for (int i = 5; i <= n; i *= 5)
            cnt2 += n / i;

        cout << min(cnt1, cnt2) << '\n';
    }
    return 0;
}