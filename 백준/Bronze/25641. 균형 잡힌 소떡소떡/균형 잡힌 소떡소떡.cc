#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

#define ll long long

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    string s;
    cin >> s;

    map<char, int> m;
    for (int n = 0; n < N; ++n)
        m[s[n]] += 1;

    if (m['s'] == m['t']) {
        cout << s << '\n';
        return 0;
    }

    int n = 0;
    while (n < N) {
        m[s[n++]] -= 1;

        if (m['s'] == m['t']) {
            cout << s.substr(n) << '\n';
            break;
        }
    }

    return 0;
}