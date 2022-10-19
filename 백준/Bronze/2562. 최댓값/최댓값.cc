#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long

using namespace std;

int N, Arr[9];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++)
		cin >> Arr[i];
	
	int pivot = Arr[0], idx = 0;
	for (int i = 1; i < 9; i++)
	{
		if (Arr[i] > pivot)
			pivot = Arr[i], idx = i;
	}

	cout << pivot << '\n';
	cout << idx + 1 << '\n';
	return 0;
}