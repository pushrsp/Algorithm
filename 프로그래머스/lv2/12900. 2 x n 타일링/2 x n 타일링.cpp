#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

#define MOD 1000000007
#define MAX 60001

using namespace std;

int DP[MAX];

int solution(int n) {
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 3;

    for (int i = 4; i <= n; ++i)
        DP[i] = (DP[i - 1] + DP[i - 2]) % MOD;
    
    return DP[n];
}