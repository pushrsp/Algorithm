#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> nums;

int main() {
    cin >> N;

    nums = vector<int>(N, 0);
    for (int i = 0; i < N; ++i)
        cin >> nums[i];

    sort(nums.begin(), nums.end());

    int sum = 0;
    for (int i = 0; i < N; ++i) {
        if (nums[i] > sum + 1)
            break;

        sum += nums[i];
    }

    cout << sum + 1 << endl;

    return 0;
}