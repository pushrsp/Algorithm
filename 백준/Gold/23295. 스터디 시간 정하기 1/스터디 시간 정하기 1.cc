#include <bits/stdc++.h>
#define INF 9876543210
#define endl '\n'
using namespace std;
using ll = long long;

ll n, t, k, s, e, tmp, ans1, ans2;
ll table[100001];
ll sum[100001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> t;
	for (ll i = 0; i < n; i++) {
		cin >> k;
		for (ll j = 0; j < k; j++) {
			cin >> s >> e;
			table[s]++;
			table[e]--;
		}
	}
    
	//스위핑
	for (ll i = 1; i <= 100000; i++) table[i] += table[i - 1];

	//누적합 구하는 작업
	//sum[i]는 1부터 i까지의 합이다!
	sum[0] = table[0];
	for (ll i = 1; i <= 100000; i++) sum[i] += sum[i - 1] + table[i];
	
   	//최대인 구간 찾는 과정!
	tmp = sum[t - 1];
	ans1 = 0;
	ans2 = t;
	for (ll i = 1; i <= 100000 - t; i++) {
		if (sum[i + t - 1] - sum[i - 1] > tmp) {
			ans1 = i;
			ans2 = i + t;
		}
		tmp = max(sum[i + t - 1] - sum[i - 1], tmp);
	}
    
	cout << ans1 << ' ' << ans2 << endl;

	return 0;
}