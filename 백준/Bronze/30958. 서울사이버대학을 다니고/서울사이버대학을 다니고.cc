#include <iostream>
#include <map>
#include <algorithm>
#include <string>

#define ll long long

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    cin.ignore();

    string s;
    getline(cin, s);

    map<char, int> m;
    for (auto &c: s) {
        if ('a' <= c && c <= 'z')
            m[c] += 1;
    }

    int ret = 0;
    for (auto &p: m)
        ret = max(ret, p.second);

    cout << ret << '\n';

    return 0;
}