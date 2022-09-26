#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int, int> UM1, UM2;
vector<int> Vec;
int N, C;

bool cmp(int a, int b) {
    if (UM1[a] == UM1[b])
        return UM2[a] < UM2[b];

    return UM1[a] > UM1[b];
}

int main() {
    cin >> N >> C;

    Vec = vector<int>(N, 0);
    for (int n = 0; n < N; ++n) {
        cin >> Vec[n];
        UM1[Vec[n]]++;

        if (UM2[Vec[n]] == 0)
            UM2[Vec[n]] = n + 1;
    }

    sort(Vec.begin(), Vec.end(), cmp);

    for (auto n: Vec)
        cout << n << " ";
    return 0;
}