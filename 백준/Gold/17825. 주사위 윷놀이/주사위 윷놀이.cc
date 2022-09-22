#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
* 스페셜 노드: 10, 20, 25, 30
* 1~5칸 까지
*/
int Board[33][6] = {
	{0,1,2,3,4,5},
	{2,2,3,4,5,6},
	{4,3,4,5,6,7},
	{6,4,5,6,7,8},
	{8,5,6,7,8,9},
	{10,21,22,23,24,25},
	{12,7,8,9,10,11},
	{14,8,9,10,11,12},
	{16,9,10,11,12,13},
	{18,10,11,12,13,14},
	{20,27,28,24,25,26},
	{22,12,13,14,15,16},
	{24,13,14,15,16,17},
	{26,14,15,16,17,18},
	{28,15,16,17,18,19},
	{30,29,30,31,24,25},
	{32,17,18,19,20,32},
	{34,18,19,20,32,32},
	{36,19,20,32,32,32},
	{38,20,32,32,32,32},
	{40,32,32,32,32,32},
	{13,22,23,24,25,26},
	{16,23,24,25,26,20},
	{19,24,25,26,20,32},
	{25,25,26,20,32,32},
	{30,26,20,32,32,32},
	{35,20,32,32,32,32},
	{22,28,24,25,26,20},
	{24,24,25,26,20,32},
	{28,30,31,24,25,26},
	{27,31,24,25,26,20},
	{26,24,25,26,20,32},
	{0,32,32,32,32,32}
};

vector<int> Move(10);
int answer = -1;

int sum_score(int turn)
{
	int sum = 0;
	int horses[4] = { 0,0,0,0 };
	bool visited[33] = { false };

	for (int i = 0; i < 10; i++)
	{
		int horse = (turn >> (i * 2)) & 3;
		int pos = horses[horse];
		int nextPos = Board[pos][Move[i]];

		if (visited[nextPos] && nextPos != 32)
			return -1;

		sum += Board[nextPos][0];
		visited[pos] = false;
		visited[nextPos] = true;
		horses[horse] = nextPos;
	}

	return sum;
}

int main()
{
	for (int i = 0; i < 10; i++)
		cin >> Move[i];

	for (int i = 0; i < (1 << 20); i++)
		answer = max(answer, sum_score(i));

	cout << answer << endl;

	return 0;
}