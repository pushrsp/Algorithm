#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long

using namespace std;

int T, W, Dp[1001][2][31];
vector<int> Vec;

int go(int idx, int pos, int count)
{
	if (count < 0)
		return -987654321;
	if (idx == T)
		return 0;

	int& ret = Dp[idx][pos][count];
	if (~ret)
		return ret;

	return ret = max(go(idx + 1, pos ^ 1, count - 1), go(idx + 1, pos, count)) + (pos == Vec[idx] - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T >> W;

	Vec = vector<int>(T);
	for (int t = 0; t < T; t++)
		cin >> Vec[t];

	memset(Dp, -1, sizeof(Dp));
	cout << max(go(0, 0, W), go(0, 1, W - 1)) << '\n';
	return 0;
}