#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<string> Vec;

void replace_string(string &s) {
    if (s.size() == 1 && s[0] == '0') {
        Vec.emplace_back("0");
        return;
    }

    while (true) {
        if (s.size() == 1)
            break;

        if (s[0] == '0')
            s.erase(s.begin());
        else
            break;
    }

    if (s[0] == '0')
        Vec.emplace_back("0");
    else
        Vec.push_back(s);
}

bool cmp_str(const string &a, const string &b) {
    if (a.size() == b.size())
        return a + b < b + a;

    return a.size() < b.size();
}

int main() {
    cin >> N;

    for (int n = 0; n < N; ++n) {
        string s;
        cin >> s;

        string temp = "";
        for (auto c: s) {
            if (48 <= c && c <= 57) {
                temp += c;
            } else {
                if (!temp.empty()) {
                    replace_string(temp);
                    temp = "";
                }
            }
        }

        if (temp.empty())
            continue;

        if (48 <= temp[0] && temp[0] <= 57)
            replace_string(temp);
    }

    sort(Vec.begin(), Vec.end(), cmp_str);
    for (string &a: Vec)
        cout << a << '\n';

    return 0;
}