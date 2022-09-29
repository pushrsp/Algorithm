#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int R, C, Answer = -1;
vector<vector<char>> Map;

int deltaY[4] = { -1,0,1,0 };
int deltaX[4] = { 0,-1,0,1 };

void go(int cnt, int visited, int nowY, int nowX)
{
	Answer = max(Answer, cnt);
	for (int i = 0; i < 4; i++)
	{
		int nextY = nowY + deltaY[i];
		int nextX = nowX + deltaX[i];

		if (nextY < 0 || nextY >= R)
			continue;
		if (nextX < 0 || nextX >= C)
			continue;
		if (visited & (1 << (Map[nextY][nextX] - 'A')))
			continue;

		int nextVisited = visited | (1 << (Map[nextY][nextX] - 'A'));
		go(cnt + 1, nextVisited, nextY, nextX);
		
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	Map = vector<vector<char>>(R, vector<char>(C));
	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			cin >> Map[y][x];
		}
	}

	go(1, 1 << (Map[0][0] - 'A'), 0, 0);
	cout << Answer << '\n';
	return 0;
}