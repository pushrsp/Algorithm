#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> coins;

int main() {
    cin >> N >> K;

    coins = vector<int>(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> coins[i];
    }

    int cnt = 0;

    while (K > 0) {
        int coin = -1;

        for (int i = 0; i < coins.size(); ++i) {
            if (K / coins[i])
                coin = coins[i];
        }

        K -= coin;
        cnt++;
    }

    cout << cnt << endl;
    return 0;
}