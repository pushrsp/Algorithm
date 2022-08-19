#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;

int main() {
    cin >> N;

    vector<int> nums(N);
    for (int n = 0; n < N; ++n)
        cin >> nums[n];

    cin >> S;

    for (int n = 0; n < N; ++n) {
        int num = nums[n];
        int idx = n;

        for (int i = n + 1; i < N; ++i) {
            if (S - (i - n) >= 0) {
                if (nums[i] > num) {
                    num = nums[i];
                    idx = i;
                }
            }
        }

        for (int i = idx; i > n; --i)
            swap(nums[i], nums[i - 1]);

        S -= (idx - n);

        if (S <= 0)
            break;
    }

    for (int n = 0; n < N; ++n)
        cout << nums[n] << " ";

    return 0;
}