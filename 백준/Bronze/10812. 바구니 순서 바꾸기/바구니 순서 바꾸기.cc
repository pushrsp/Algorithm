#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int> arr; // 바구니를 저장할 벡터

	for (int i = 1; i <= N; i++) 
	{
		arr.push_back(i);
	}

	for (int i = 0; i < M; i++)
	{
		int A, B, C; // A: 시작, B: 끝, C: 중간(기준)
		cin >> A >> B >> C;
		rotate(arr.begin() + (A - 1), arr.begin() + (C - 1), arr.begin() + B);
	}

	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " "; // 출력
	}
	cout << "\n";

	return 0;
}