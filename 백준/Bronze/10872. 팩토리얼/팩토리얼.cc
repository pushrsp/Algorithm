#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long

using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	if (N == 0)
	{
		cout << '1' << '\n';
	}
	else
	{
		int sum = N;
		for (int i = N - 1; i >= 1; i--)
			sum *= i;

		cout << sum << '\n';
	}
	return 0;
}