#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long

using namespace std;

int N, S, Arr[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> S;

    for (int i = 0; i < N; ++i)
        cin >> Arr[i];

    int left = 0, right = 0, sum = 0, answer = INT32_MAX;
    while (left <= right) {

        if (sum >= S) {
            answer = min(answer, right - left);
            sum -= Arr[left++];
        } else if (right == N) {
            break;
        } else {
            sum += Arr[right++];
        }
    }

    if (answer == INT32_MAX)
        cout << 0 << '\n';
    else
        cout << answer << '\n';
    return 0;
}