#include <iostream>
#include <vector>
#include <cstring>

#define MAX 10001

using namespace std;

int X, Coins[4], Nums[4] = {1, 5, 10, 25};
int DP[MAX][5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> X;
    for (int &coin: Coins)
        cin >> coin;

    ::memset(DP, -1, sizeof(DP));

    DP[0][0] = 0;
    DP[0][1] = 0;
    DP[0][2] = 0;
    DP[0][3] = 0;
    DP[0][4] = 0;

    for (int x = 1; x <= X; ++x) {
        for (int i = 0; i < 4; ++i) {
            if (DP[x][i] == -1)
                DP[x][i] = 0;

            if (x - Nums[i] < 0)
                continue;

            if (DP[x - Nums[i]][4] > DP[x][4]) {
                if (Coins[i] >= DP[x - Nums[i]][i] + 1) {
                    for (int j = 0; j < 4; ++j)
                        DP[x][j] = DP[x - Nums[i]][j];

                    DP[x][4] = DP[x - Nums[i]][4] + 1;
                    DP[x][i] += 1;
                }
            }
        }
    }

    for (int i = 0; i < 4; ++i)
        cout << DP[X][i] << ' ';

    return 0;
}