#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main() {
	cin >> N;

	vector<int> male_tall;
	vector<int> male_small;
	vector<int> female_tall;
	vector<int> female_small;

	for (int n = 0; n < N; ++n) {
		int t;
		cin >> t;

		if (t < 0)
			male_small.push_back(t);
		else
			male_tall.push_back(t);
	}

	for (int n = 0; n < N; ++n) {
		int t;
		cin >> t;

		if (t < 0)
			female_small.push_back(t);
		else
			female_tall.push_back(t);
	}

	sort(male_small.begin(), male_small.end(), less<int>());
	sort(female_tall.begin(), female_tall.end(), less<int>());

	int male = 0, female = female_tall.size() - 1, answer = 0;
	while (male < male_small.size() && female >= 0) {
		int m_height = abs(male_small[male]);
		int f_height = female_tall[female];

		if (f_height < m_height) {
			answer++;
			male++;
			female--;
		}
		else {
			female--;
		}
	}

	sort(male_tall.begin(), male_tall.end(), less<int>());
	sort(female_small.begin(), female_small.end(), less<int>());

	male = male_tall.size() - 1, female = 0;
	while (female < female_small.size() && male >= 0) {
		int f_height = abs(female_small[female]);
		int m_height = male_tall[male];

		if (m_height < f_height) {
			answer++;
			female++;
			male--;
		}
		else {
			male--;
		}
	}

	cout << answer << endl;
	return 0;
}