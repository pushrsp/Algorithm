#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <stack>

#define ll long long

using namespace std;

int N, M, Map[1001][1001], DP[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;

	bool isZero = true;
	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < M; j++)
		{
			Map[i][j + 1] = s[j] - '0';
			if (Map[i][j + 1])
				DP[i][j + 1] = 1, isZero = false;
		}
	}

	if (isZero)
	{
		cout << 0 << '\n';
		return 0;
	}

	int answer = 0;
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= M; x++)
		{
			if (DP[y][x] && DP[y - 1][x] && DP[y][x - 1] && DP[y - 1][x - 1])
			{
				DP[y][x] = min(min(DP[y - 1][x - 1], DP[y - 1][x]), DP[y][x - 1]) + 1;
				answer = max(answer, DP[y][x]);
			}
		}
	}

	if (answer == 0)
		cout << 1 << '\n';
	else
		cout << answer * answer << '\n';
	return 0;
}