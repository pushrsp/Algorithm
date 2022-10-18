#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long

using namespace std;

int N;
vector<int> Rope;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	Rope = vector<int>(N);
	for (int n = 0; n < N; n++)
		cin >> Rope[n];
	
	sort(Rope.begin(), Rope.end());
	
	int ret = Rope.back(), k = 1, sum = 0;
	Rope.pop_back();

	while (!Rope.empty())
	{
		k++;
		ret = max(ret, k * Rope.back());
		Rope.pop_back();
	}

	cout << ret << '\n';
	return 0;
}