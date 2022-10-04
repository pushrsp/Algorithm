#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, Mn = INT32_MAX, Mx = INT32_MIN;
vector<int> Nums, Opers(4);

int oper(int i, int a, int b) {
    if (i == 0)
        return a + b;
    else if (i == 1)
        return a - b;
    else if (i == 2)
        return a * b;
    else
        return a / b;
}

void go(int idx, int sum) {
    if (idx == Nums.size() - 1) {
        Mn = min(Mn, sum);
        Mx = max(Mx, sum);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (Opers[i] == 0)
            continue;

        Opers[i]--;
        go(idx + 1, oper(i, sum, Nums[idx + 1]));
        Opers[i]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    Nums = vector<int>(N);
    for (int n = 0; n < N; ++n)
        cin >> Nums[n];

    for (int i = 0; i < 4; ++i)
        cin >> Opers[i];

    go(0, Nums[0]);

    cout << Mx << '\n';
    cout << Mn << '\n';

    return 0;
}