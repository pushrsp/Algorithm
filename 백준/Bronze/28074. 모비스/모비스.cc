#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

#define ll long long

using namespace std;

int A[30];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); ++i)
        A[s[i] - 'A'] += 1;

    if (A['M' - 'A'] > 0 && A['O' - 'A'] > 0 && A['B' - 'A'] > 0 && A['I' - 'A'] > 0 && A['S' - 'A'] > 0)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';

    return 0;
}