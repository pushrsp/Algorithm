#include <iostream>
#include <queue>

#define ll long long

using namespace std;

int N, K;
ll T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K >> T;

    ll size;
    priority_queue<ll> pq1, pq2;
    for (int n = 0; n < N; ++n) {
        cin >> size;
        pq1.push(-size);
    }

    while ((!pq1.empty() || !pq2.empty()) && K > 0) {
        while (!pq1.empty() && -pq1.top() < T) {
            pq2.push(-pq1.top());
            pq1.pop();
        }

        if (!pq2.empty()) {
            T += pq2.top();
            pq2.pop();
        }

        K--;
    }

    cout << T << '\n';

    return 0;
}