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

    string s1, s2;
    s1 = s.substr(0, N / 2);

    if (N % 2)
        s2 = s.substr(N / 2 + 1);
    else
        s2 = s.substr(N / 2);

    reverse(s2.begin(), s2.end());

    int ret = 0;
    for (int i = 0; i < s1.length(); ++i) {
        if (s1[i] != s2[i])
            ret += 1;
    }

    cout << ret << '\n';

    return 0;
}