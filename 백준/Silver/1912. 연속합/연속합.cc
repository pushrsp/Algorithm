#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int sum = 0, answer = INT32_MIN;
    for (int n = 0; n < N; ++n) {
        int i;
        cin >> i;

        sum += i;
        answer = max(answer, sum);
        if (sum < 0)
            sum = 0;
    }

    cout << answer << '\n';
    return 0;
}