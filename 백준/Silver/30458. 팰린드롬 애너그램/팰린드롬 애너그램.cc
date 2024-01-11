#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int N, A[30];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    string s;
    cin >> s;

    for (int n = 0; n < N; ++n)
        A[s[n] - 'a'] += 1;

    if (s.length() % 2)
        A[s[N / 2] - 'a'] -= 1;

    for (int i = 0; i < 26; ++i) {
        if (A[i] % 2) {
            cout << "No" << '\n';
            return 0;
        }
    }

    cout << "Yes" << '\n';

    return 0;
}