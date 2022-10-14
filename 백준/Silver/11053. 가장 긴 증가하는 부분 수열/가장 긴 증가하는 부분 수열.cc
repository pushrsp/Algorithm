#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long

using namespace std;

int N, Arr[1001], Len;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int n = 0; n < N; n++)
	{
		int num;
		cin >> num;

		auto pos = lower_bound(Arr, Arr + Len, num);
		if (*pos == 0)
			Len++;

		*pos = num;
	}

	cout << Len << '\n';

	return 0;
}