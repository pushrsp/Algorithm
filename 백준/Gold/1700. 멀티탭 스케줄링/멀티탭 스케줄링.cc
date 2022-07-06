#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

int N, K;
vector<int> vec;
int order[101], multi_tab[101];

int main() {
    cin >> N >> K;
    for (int i = 0; i < K; ++i)
        cin >> order[i];

    int cnt = 0;
    for (int i = 0; i < K; ++i) {
        bool check = false;

        for (int j = 0; j < N; ++j) {
            if (multi_tab[j] == order[i]) {
                check = true;
                break;
            }
        }

        if (check)
            continue;

        for (int j = 0; j < N; ++j) {
            if (!multi_tab[j]) {
                multi_tab[j] = order[i];
                check = true;
                break;
            }
        }

        if (check)
            continue;

        int idx, deviceIdx = -1;
        for (int j = 0; j < N; j++) {
            int lastIdx = 0;
            for (int k = i + 1; k < K; k++) {
                if (multi_tab[j] == order[k])
                    break;
                lastIdx++;
            }
            if (lastIdx > deviceIdx) {
                idx = j;
                deviceIdx = lastIdx;
            }
        }
        multi_tab[idx] = order[i];
        cnt++;
    }

    cout << cnt << endl;
    return 0;
}