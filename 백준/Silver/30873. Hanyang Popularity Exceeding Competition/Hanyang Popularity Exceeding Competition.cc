#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int p, c, ret = 0;
    for (int n = 0; n < N; ++n) {
        cin >> p >> c;

        if (abs(p - ret) <= c)
            ret += 1;
    }

    cout << ret << '\n';

    return 0;
}