#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long

using namespace std;
int N;
ll Dp[31][31];

ll go(int full, int half)
{
	if (full == 0 && half == 0)
		return 1;
	if (Dp[full][half])
		return Dp[full][half];

	ll& ret = Dp[full][half];
	if (full > 0)
		ret += go(full - 1, half + 1);
	if (half > 0)
		ret += go(full, half - 1);

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		cin >> N;
		if (N == 0)
			break;

		if (N == 1 || N == 2)
		{
			cout << N << '\n';
			continue;
		}

		cout << go(N, 0) << '\n';
	}
	return 0;
}