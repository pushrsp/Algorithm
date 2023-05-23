#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> GetTable(string pattern) {
    vector<int> ret(pattern.length());
    int j = 0;

    for (int i = 1; i < pattern.length(); ++i) {
        while (pattern[j] != pattern[i] && j > 0)
            j = ret[j - 1];

        if (pattern[j] == pattern[i])
            ret[i] = ++j;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;

    int ret = 0;
    for (int i = 0; i < s.length(); ++i) {
        vector<int> table = GetTable(s.substr(i));

        for (int j = 0; j < table.size(); ++j)
            ret = max(ret, table[j]);
    }

    cout << ret << '\n';

    return 0;
}