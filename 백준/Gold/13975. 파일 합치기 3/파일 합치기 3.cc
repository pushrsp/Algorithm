#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

#define ll long long

using namespace std;

int T, K;
ll N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> K;

        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int k = 0; k < K; ++k) {
            cin >> N;
            pq.push(N);
        }


        ll ret = 0;
        while (pq.size() != 1) {
            ll n1 = pq.top();
            pq.pop();

            ll n2 = pq.top();
            pq.pop();

            ll sum = n1 + n2;
            ret += sum;

            pq.push(sum);
        }

        cout << ret << '\n';
    }
    return 0;
}