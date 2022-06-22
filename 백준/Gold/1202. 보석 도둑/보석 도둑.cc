#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;
vector<pair<int, int>> j;
vector<int> b;

bool cmpPair(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.first < b.first;
}

bool cmpInt(const int& a, const int& b)
{
	return a < b;
}

priority_queue<int, vector<int>, less<int>> pq;

int main() {
	cin >> N >> K;

	j = vector<pair<int, int>>(N);
	for (int i = 0; i < N; i++)
		cin >> j[i].first >> j[i].second;

	b = vector<int>(K);
	for (int i = 0; i < K; i++)
		cin >> b[i];

	sort(j.begin(), j.end(), cmpPair);
	sort(b.begin(), b.end(), cmpInt);

	uint64_t result = 0;
	int idx = 0;
	for (int i = 0; i < K; i++)
	{
		while (idx < j.size())
		{
			if (j[idx].first > b[i])
				break;

			pq.push(j[idx].second);
			idx++;
		}

		if (!pq.empty())
		{
			result += pq.top();
			pq.pop();
		}
	}

	cout << result << endl;

	return 0;
}