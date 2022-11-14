#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long

using namespace std;
int N, DP[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	vector<pair<int, int>> vec(N);
	for (int n = 0; n < N; n++)
		cin >> vec[n].first;
	for (int n = 0; n < N; n++)
		cin >> vec[n].second;
	
	for (auto& v : vec)
	{
		for (int i = 99; i >= v.first; i--)
			DP[i] = max(DP[i], DP[i - v.first] + v.second);
	}

	cout << DP[99] << '\n';

	return 0;
}