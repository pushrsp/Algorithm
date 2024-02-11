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

    vector<int> vec(N);
    for (int n = 0; n < N; ++n)
        cin >> vec[n];

    int ret = 0, offset = -1;
    for (int n = N - 1; n >= 0; --n) {
        offset = max(offset, vec[n]);
        ret = max(ret, offset - vec[n]);
    }

    cout << ret << '\n';

    return 0;
}