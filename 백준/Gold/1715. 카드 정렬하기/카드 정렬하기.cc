#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<int> nums;

int main() {
    cin >> N;

    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;

        pq.push(n);
    }

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    if (N == 2) {
        cout << nums[0] + nums[1] << endl;
        return 0;
    }

    int sum = 0;
    while (!pq.empty()) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        sum += a;
        sum += b;

        if (!pq.empty())
            pq.push(a + b);
    }

    cout << sum;
    return 0;
}