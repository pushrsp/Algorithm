#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long

using namespace std;

ll N, M, Arr[10001];

bool is_valid(ll mid)
{
	ll cnt = M;
	for (int i = 0; i < M; i++)
		cnt += mid / Arr[i];

	return cnt >= N;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int m = 0; m < M; m++)
		cin >> Arr[m];

	if (N <= M)
	{
		cout << N << '\n';
		return 0;
	}

	ll left = 0, right = 60000000000, mid, ret;
	while (left <= right)
	{
		mid = (left + right) / 2;
		
		if (is_valid(mid))
		{
			ret = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	ll cnt = M;
	for (int i = 0; i < M; i++)
		cnt += (ret - 1) / Arr[i];

	for (int i = 0; i < M; i++)
	{
		if (ret % Arr[i] == 0)
			cnt++;

		if (cnt == N)
		{
			cout << i + 1 << '\n';
			return 0;
		}
	}

	return 0;
}