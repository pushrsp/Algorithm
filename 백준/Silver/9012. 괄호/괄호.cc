#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        stack<char> st;

        bool success = true;
        for (auto c: s) {
            if (c == '(') {
                st.push(c);
            } else {
                if (st.empty()) {
                    success = false;
                    break;
                }

                st.pop();
            }
        }

        if (!success) {
            cout << "NO" << '\n';
        } else {
            if (!st.empty())
                cout << "NO" << '\n';
            else
                cout << "YES" << '\n';
        }
    }
    return 0;
}