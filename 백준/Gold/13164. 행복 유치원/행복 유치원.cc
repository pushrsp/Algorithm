#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, K;

bool cmp_int(const int a, const int b) {
    return a > b;
}

int main() {
    cin >> N >> K;

    vector<int> people(N);
    for (int n = 0; n < N; ++n)
        cin >> people[n];

    vector<int> gap;
    for (int n = 0; n < people.size() - 1; ++n)
        gap.push_back(abs(people[n] - people[n + 1]));

    sort(gap.begin(), gap.end(), cmp_int);

    int sum = 0;
    for (int n = K - 1; n < people.size() - 1; ++n)
        sum += gap[n];

    cout << sum << endl;
    return 0;
}