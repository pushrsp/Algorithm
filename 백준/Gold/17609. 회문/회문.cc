#include <iostream>
#include <algorithm>

using namespace std;

int T;
string S;

int go(int left, int right, int remove, string &s) {
    while (left < right) {
        if (s[left] != s[right]) {
            if (remove == 0) {
                if (go(left + 1, right, 1, s) == 0 || go(left, right - 1, 1, s) == 0)
                    return 1;
            }

            return 2;
        } else {
            left++, right--;
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> S;

        cout << go(0, S.length() - 1, 0, S) << '\n';
    }
    return 0;
}