#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long

using namespace std;
int N;

void go(int n, vector<int>& prev)
{
	if (n == prev[n])
		return;

	cout << n << ' ';
	go(prev[n], prev);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	vector<int> dp(N + 1, INT32_MAX);
	vector<int> prev(N + 1, -1);

	dp[0] = 0;
	dp[1] = 0;

	prev[1] = 1;

	for (int i = 1; i < N; i++)
	{
		if (i * 3 <= N && dp[i] + 1 < dp[i * 3])
		{
			dp[i * 3] = dp[i] + 1;
			prev[i * 3] = i;
		}

		if (i * 2 <= N && dp[i] + 1 < dp[i * 2])
		{
			dp[i * 2] = dp[i] + 1;
			prev[i * 2] = i;
		}

		if (i + 1 <= N && dp[i] + 1 < dp[i + 1])
		{
			dp[i + 1] = dp[i] + 1;
			prev[i + 1] = i;
		}
	}

	cout << dp[N] << '\n';
	go(N, prev);
	cout << 1 << '\n';
	return 0;
}