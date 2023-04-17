#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

#define MAX 100001

using namespace std;

int N, M;
int J[MAX], DP[MAX], Sum[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        cin >> J[i];
        Sum[i] = Sum[i - 1] + J[i];
    }

    int ret = 0, temp = 0;
    for (int i = M + 1; i <= N; ++i) {
        temp = min(temp, Sum[i - M]);
        ret = max(Sum[i] - temp, ret);
    }

    cout << ret << '\n';
    return 0;
}