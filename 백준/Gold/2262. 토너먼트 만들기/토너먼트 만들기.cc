#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    vector<int> vec(N + 2);
    for (int n = 1; n <= N; ++n)
        cin >> vec[n];

    int ret = 0;
    for (int i = N; i > 1; --i) {
        int j;
        for (j = 1; j <= N; j++) {
            if (vec[j] == i)
                break;
        }

        ret += min(vec[j] - vec[j + 1], vec[j] - vec[j - 1]);
        for (; j <= N; j++)
            vec[j] = vec[j + 1];
    }

    cout << ret << '\n';
    return 0;
}