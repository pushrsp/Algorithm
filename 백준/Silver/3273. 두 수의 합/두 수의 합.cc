#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, X;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    cin >> N;

    vector<int> vec(N);
    for (int n = 0; n < N; ++n)
        cin >> vec[n];

    cin >> X;
    sort(vec.begin(), vec.end());

    int left = 0, right = N - 1, answer = 0;
    while (left < right) {
        int sum = vec[left] + vec[right];
        if (sum == X) {
            answer++;
            left++;
            right--;
        } else if (sum > X) {
            right--;
        } else {
            left++;
        }
    }

    cout << answer << '\n';
    return 0;
}