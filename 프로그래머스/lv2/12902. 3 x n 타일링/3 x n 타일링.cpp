#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

#define ll long long
#define MOD 1000000007
#define MAX 5001

using namespace std;

ll DP[MAX];

int solution(int n) {
    if (n % 2 == 1)
        return 0;

    DP[0] = 1;
    DP[2] = 3;
    for (int i = 4; i <= n; i += 2) {
        DP[i] = DP[i - 2] * 3;
        for (int j = i - 4; j >= 0; j -= 2)
            DP[i] += DP[j] * 2;

        DP[i] %= MOD;
    }

    return (int) DP[n];
}