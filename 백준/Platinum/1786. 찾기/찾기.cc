#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

vector<int> Table;

void CreateTable(string &pattern) {
    Table = vector<int>(pattern.length());

    int j = 0;
    for (int i = 1; i < pattern.length(); ++i) {
        while (j > 0 && pattern[j] != pattern[i])
            j = Table[j - 1];

        if (pattern[i] == pattern[j])
            Table[i] = ++j;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    getline(cin, s);

    string pattern;
    getline(cin, pattern);

    CreateTable(pattern);

    int j = 0, ret1 = 0;
    vector<int> ret2;

    for (int i = 0; i < s.length(); ++i) {
        while (j > 0 && s[i] != pattern[j])
            j = Table[j - 1];

        if (s[i] == pattern[j]) {
            if (j == pattern.length() - 1) {
                j = Table[j];
                ret1++;
                ret2.push_back(i - static_cast<int>(pattern.length()) + 2);
            } else {
                j++;
            }
        }
    }

    cout << ret1 << '\n';
    for (auto &a: ret2)
        cout << a << ' ';

    return 0;
}