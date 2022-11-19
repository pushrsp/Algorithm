#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

double A, B, Answer = 0.0;
double DP[20][20][20];

bool IsPrime(int a) {
    if (a == 0 || a == 1)
        return false;

    for (int i = 2; i < a; ++i) {
        if (a % i == 0)
            return false;
    }

    return true;
}

double go(int count, int a, int b) {
    if (count == 18) {
        if (IsPrime(a) || IsPrime(b))
            return 1.0;

        return 0.0;
    }

    double &ret = DP[count][a][b];
    if (ret > -0.1)
        return ret;

    ret = 0.0;
    ret += go(count + 1, a + 1, b) * A * (1 - B);
    ret += go(count + 1, a, b + 1) * (1 - A) * B;
    ret += go(count + 1, a + 1, b + 1) * A * B;
    ret += go(count + 1, a, b) * (1 - A) * (1 - B);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;

    A /= 100, B /= 100;
    memset(DP, -1, sizeof(DP));

    printf("%.6lf", go(0, 0, 0));
    return 0;
}