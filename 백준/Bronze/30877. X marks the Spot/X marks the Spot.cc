#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

#define ll long long

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    string ret, s1, s2;
    for (int n = 0; n < N; ++n) {
        cin >> s1 >> s2;

        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] == 'x' || s1[i] == 'X') {
                if ('a' <= s2[i] && s2[i] <= 'z')
                    ret.push_back(s2[i] - 32);
                else
                    ret.push_back(s2[i]);

                break;
            }
        }
    }

    cout << ret << '\n';

    return 0;
}