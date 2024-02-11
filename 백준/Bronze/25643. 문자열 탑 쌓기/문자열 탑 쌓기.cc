#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

#define ll long long

using namespace std;

int N, M;

bool is_valid(string &s1, string &s2) {
    for (int m = M - 1; m >= 0; --m) {
        if (s1.substr(m) == s2.substr(0, M - m))
            return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    vector<string> vec(N);
    for (int n = 0; n < N; ++n)
        cin >> vec[n];

    string floor = vec[0];
    for (int n = 1; n < N; ++n) {
        bool success = is_valid(vec[n], floor) || is_valid(floor, vec[n]);

        if (!success) {
            cout << 0 << '\n';
            return 0;
        }

        floor = vec[n];
    }

    cout << 1 << '\n';

    return 0;
}