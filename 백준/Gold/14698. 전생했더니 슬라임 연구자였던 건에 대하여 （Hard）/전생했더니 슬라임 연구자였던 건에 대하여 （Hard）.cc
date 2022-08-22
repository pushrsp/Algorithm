#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
const long long int mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        priority_queue<long long int, vector<long long int>, greater<long long int >> pq;
        for (int i = 0; i < n; i++) {
            long long int num;
            cin >> num;
            pq.push(num);
        }
        long long int score = 1;
        while (pq.size() >= 2) {
            long long int one = pq.top();
            pq.pop();
            long long int two = pq.top();
            pq.pop();
            score *= (((one % mod) * (two % mod)) % mod);
            pq.push(one * two);
            score %= mod;
        }
        cout << score << "\n";
    }
}