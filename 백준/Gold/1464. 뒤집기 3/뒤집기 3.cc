#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> S;

    string s = S.substr(0, 1);
    for (int i = 1; i < S.length(); ++i) {
        if (s[i - 1] < S[i])
            s = S[i] + s;
        else
            s += S[i];
    }

    reverse(s.begin(), s.end());
    cout << s << '\n';
    return 0;
}