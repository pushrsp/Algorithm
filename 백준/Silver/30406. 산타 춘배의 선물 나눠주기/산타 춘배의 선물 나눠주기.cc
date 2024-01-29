#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

#define ll long long

using namespace std;

int N, A[4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int num;
    for (int n = 0; n < N; ++n) {
        cin >> num;
        A[num] += 1;
    }

    int ret = 0;

    int mn = min(A[0], A[3]);
    ret += mn * 3;
    A[0] -= mn, A[3] -= mn;

    mn = min(A[1], A[2]);
    ret += mn * 3;
    A[1] -= mn, A[2] -= mn;

    vector<int> temp;
    for (int i = 0; i <= 3; ++i) {
        if (A[i] > 0)
            temp.push_back(i);
    }

    if (temp.size() > 1)
        ret += (temp[0] ^ temp[1]) * min(A[temp[0]], A[temp[1]]);

    cout << ret << '\n';

    return 0;
}