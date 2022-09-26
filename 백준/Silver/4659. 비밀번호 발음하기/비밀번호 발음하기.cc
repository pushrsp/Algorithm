#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

void Print(string &s, bool success) {
    cout << "<" << s << "> " << "is ";

    if (success)
        cout << "acceptable." << '\n';
    else
        cout << "not acceptable." << '\n';
}

int main() {
    string s;

    vector<bool> visited(26, false);
    visited['a' - 'a'] = true;
    visited['e' - 'a'] = true;
    visited['i' - 'a'] = true;
    visited['o' - 'a'] = true;
    visited['u' - 'a'] = true;
    while (getline(cin, s)) {
        if (s == "end")
            break;

        bool success = false;
        for (char c: s) {
            if (visited[c - 'a'])
                success = true;
        }

        if (!success) {
            Print(s, success);
            continue;
        }

        char cur = s[0];
        int cnt = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (cur != s[i]) {
                cnt = 1;
                cur = s[i];
            } else {
                cnt++;

                if (cnt >= 2) {
                    if (cur == 'e' || cur == 'o') {
                        cnt = 0;
                        continue;
                    } else {
                        break;
                    }
                }
            }
        }

        if (cnt == 2) {
            Print(s, false);
            continue;
        }

        bool c = visited[s[0] - 'a'];
        cnt = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (visited[s[i] - 'a'] == c) {
                cnt++;
            } else {
                c = visited[s[i] - 'a'];
                cnt = 1;
            }

            if (cnt == 3)
                break;
        }

        if (cnt == 3) {
            Print(s, false);
            continue;
        }

        Print(s, true);
    }
    return 0;
}