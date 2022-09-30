#include <iostream>
#include <sstream>
#include <deque>
#include <algorithm>

using namespace std;

int T;

deque<string> split(string &s, char c) {
    deque<string> ret;
    stringstream ss(s);
    string segment;

    while (getline(ss, segment, c))
        ret.push_back(segment);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--) {
        string p;
        cin >> p;

        int n;
        cin >> n;

        string s;
        cin >> s;

        s = s.substr(1, s.length() - 2);
        deque<string> num_str = split(s, ',');
        bool rev = false;
        bool success = true;

        for (char cmd: p) {
            if (cmd == 'R')
                rev = !rev;
            else {
                if (num_str.empty()) {
                    success = false;
                    continue;
                }

                if (rev)
                    num_str.pop_back();
                else
                    num_str.pop_front();
            }
        }

        if (!success) {
            cout << "error" << '\n';
            continue;
        }

        if (rev)
            reverse(num_str.begin(), num_str.end());

        cout << '[';
        for (int i = 0; i < num_str.size(); ++i) {
            cout << num_str[i];

            if (i != num_str.size() - 1)
                cout << ',';
        }
        cout << ']' << '\n';
    }
    return 0;
}