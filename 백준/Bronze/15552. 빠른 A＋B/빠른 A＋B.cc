#include <iostream>
#include <algorithm>

using namespace std;

int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        cout << a + b << '\n';
    }
    return 0;
}