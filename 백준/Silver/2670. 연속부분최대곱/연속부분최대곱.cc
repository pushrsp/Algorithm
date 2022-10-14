#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long

using namespace std;

int N;
double Arr[10001];

float max(double a, double b)
{
	if (a >= b)
		return a;

	return b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int n = 0; n < N; n++)
		cin >> Arr[n];

	double ret = 0.0f;
	for (int i = 0; i < N; i++)
	{
		double sum = Arr[i], cmp = Arr[i];
		for (int j = i + 1; j < N; j++)
		{
			double a = sum * Arr[j];
			cmp = max(cmp, a);
			sum = a;
		}

		ret = max(ret, cmp);
	}

	printf("%.3lf", ret);
	return 0;
}