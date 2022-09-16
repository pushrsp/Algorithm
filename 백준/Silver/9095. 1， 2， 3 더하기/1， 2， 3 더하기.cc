#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;

int main()
{
	cin >> T;

	vector<int> dp(12);

	dp[1] = 1; // 1
	dp[2] = 2; // 1 + 1, 2
	dp[3] = 4; // 1 + 1 + 1, 2 + 1, 1 + 2, 3

	for (int i = 4; i < 12; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	
	while (T--)
	{
		int n;
		cin >> n;

		cout << dp[n] << endl;
	}
}