#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;

int main() {
    cin >> N >> M;

    vector<int> vec(N);
    for (int n = 0; n < N; ++n)
        cin >> vec[n];

    int left = 0, right = 0, sum = 0, cnt = 0;
    while (right <= N) {
        if (sum >= M) {
            sum -= vec[left];
            left++;
        } else {
            sum += vec[right];
            right++;
        }

        if (sum == M)
            cnt++;
    }

    cout << cnt << endl;
    return 0;
}