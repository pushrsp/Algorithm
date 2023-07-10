#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    vector<ll> vec(N);
    for (int n = 0; n < N; ++n)
        cin >> vec[n];

    sort(vec.begin(), vec.end());

    int ret = 0;
    for (int n = 0; n < N; ++n) {
        int left = 0, right = N - 1;
        while (left < right) {
            if (left == n) {
                left++;
                continue;
            }

            if (right == n) {
                right--;
                continue;
            }

            if (vec[n] > vec[left] + vec[right]) {
                left++;
            } else if (vec[n] == vec[left] + vec[right]) {
                ret += 1;
                break;
            } else {
                right--;
            }
        }
    }

    cout << ret << '\n';

    return 0;
}