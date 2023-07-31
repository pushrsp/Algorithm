#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple <ll, ll, ll, ll, ll> tl;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 300002;
int cnt[N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		cnt[a[i]]++;
	}

	sort(a.begin(), a.end());
	ll ans = 0;

	for (int i = 0; i < n; i++)
	{
		ll x = a[i];
		if (cnt[x] == 0) continue;
		cnt[x]--;
		ll nx = x + 1, len = 1;
		while (true)
		{
			if (cnt[nx] == 0)
			{
				ans += len * (nx - 1);
				break;
			}
			cnt[nx]--; 
			nx++; len++;
		}
	}

	cout << ans;
}