#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

bool is_pal(int offset, int d, string &s) {
    string cmp1 = "", cmp2 = "";

    for (int i = 0; i < d; ++i)
        cmp1 += s[i];

    for (int i = d + offset; i < s.size(); ++i)
        cmp2 += s[i];

    reverse(cmp2.begin(), cmp2.end());
    if (cmp1 != cmp2)
        return false;
    else
        return true;
}

int main() {
    string s;
    cin >> s;
    cout << is_pal(s.size() % 2, s.size() / 2, s) << endl;
    return 0;
}