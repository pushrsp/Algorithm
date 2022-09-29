#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, Comp[11], Visited[11], Population[11];
vector<int> Adj[11];

pair<int, int> dfs(int here, int value)
{
	Visited[here] = 1;
	pair<int, int> ret = { 1, Population[here] };

	for (int there : Adj[here])
	{
		if (Comp[there] != value)
			continue;
		if (Visited[there])
			continue;

		pair<int, int> temp = dfs(there, value);
		ret.first += temp.first;
		ret.second += temp.second;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> Population[i];

	int t;
	for (int i = 1; i <= N; i++)
	{
		cin >> M;
		for (int j = 0; j < M; j++)
		{
			cin >> t;
			Adj[i].push_back(t);
			Adj[t].push_back(i);
		}
	}

	int ret = INT32_MAX;
	for (int i = 1; i < (1 << N) - 1; i++)
	{
		fill(Comp, Comp + 11, 0);
		fill(Visited, Visited + 11, 0);

		int idx1 = -1, idx2 = -1;
		for (int j = 0; j < N; j++)
		{
			if (i & (1 << j))
			{
				Comp[j + 1] = 1;
				idx1 = j + 1;
			}
			else
			{
				idx2 = j + 1;
			}
		}

		pair<int, int> c1 = dfs(idx1, 1);
		pair<int, int> c2 = dfs(idx2, 0);

		if (c1.first + c2.first == N)
			ret = min(ret, abs(c1.second - c2.second));
	}

	if (ret == INT32_MAX)
		cout << -1 << '\n';
	else
		cout << ret << '\n';

	return 0;
}