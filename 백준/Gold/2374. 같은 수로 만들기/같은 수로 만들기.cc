#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>

#define ll long long

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    unordered_set<ll> us;

    ll mx = 0;
    vector<ll> vec(N);
    for (int n = 0; n < N; ++n) {
        cin >> vec[n];

        if (us.find(vec[n]) == us.end()) {
            mx = max(mx, vec[n]);
            pq.push(vec[n]);
            us.insert(vec[n]);
        }
    }

    ll ret = 0;
    while (!pq.empty() && pq.top() != mx) {
        ll num = pq.top();
        pq.pop();


        vector<int> temp;
        for (int i = 0; i < N; ++i) {
            if (vec[i] == num)
                temp.push_back(i);
        }

        temp.push_back(1001);

        int count = 0;
        for (int i = 0; i < temp.size() - 1; ++i) {
            if (temp[i + 1] != temp[i] + 1)
                count += 1;

            vec[temp[i]] = pq.top();
        }

        ret += (pq.top() - num) * count;
    }

    cout << ret << '\n';
    return 0;
}