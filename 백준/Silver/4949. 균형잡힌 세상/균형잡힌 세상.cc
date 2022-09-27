#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    while (true) {
        string s;
        getline(cin, s);

        if (s == ".")
            break;

        stack<char> st;
        bool success = true;
        for (char c: s) {
            if (c == '(')
                st.push(c);

            if (c == '[')
                st.push(c);

            if (c == ')') {
                if (st.empty()) {
                    success = false;
                    break;
                } else {
                    if (st.top() != '(') {
                        success = false;
                        break;
                    } else {
                        st.pop();
                    }
                }
            }

            if (c == ']') {
                if (st.empty()) {
                    success = false;
                    break;
                } else {
                    if (st.top() != '[') {
                        success = false;
                        break;
                    } else {
                        st.pop();
                    }
                }
            }
        }

        if (st.empty() && success)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}