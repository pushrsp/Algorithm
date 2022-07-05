#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    bool done = false;
    while (true) {
        if (s.size() == t.size()) {
            if (s == t)
                done = true;

            break;
        }

        char c = t[t.size() - 1];

        if (c == 'A') {
            t.pop_back();
        } else {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }

    cout << done << endl;
    return 0;
}