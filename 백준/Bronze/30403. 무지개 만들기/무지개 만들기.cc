#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

#define ll long long

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    string s;
    cin >> s;

    set<char> a;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'r') {
            a.insert(s[i]);
        } else if (s[i] == 'o') {
            a.insert(s[i]);
        } else if (s[i] == 'y') {
            a.insert(s[i]);
        } else if (s[i] == 'g') {
            a.insert(s[i]);
        } else if (s[i] == 'b') {
            a.insert(s[i]);
        } else if (s[i] == 'i') {
            a.insert(s[i]);
        } else if (s[i] == 'v') {
            a.insert(s[i]);
        }
    }

    set<char> b;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'R') {
            b.insert(s[i]);
        } else if (s[i] == 'O') {
            b.insert(s[i]);
        } else if (s[i] == 'Y') {
            b.insert(s[i]);
        } else if (s[i] == 'G') {
            b.insert(s[i]);
        } else if (s[i] == 'B') {
            b.insert(s[i]);
        } else if (s[i] == 'I') {
            b.insert(s[i]);
        } else if (s[i] == 'V') {
            b.insert(s[i]);
        }
    }

    if (a.size() == 7 || b.size() == 7) {
        if (a.size() == 7 && b.size() == 7)
            cout << "YeS" << '\n';
        else if (a.size() != 7 && b.size() == 7)
            cout << "YES" << '\n';
        else if (a.size() == 7 && b.size() != 7)
            cout << "yes" << '\n';

        return 0;
    }

    cout << "NO!" << '\n';

    return 0;
}