#include <iostream>
#include <algorithm>

using namespace std;

int N, Arr1[1001], Arr2[1001], Prev[1001];

void go(int idx) {
    if (idx == -1)
        return;

    go(Prev[idx]);
    cout << Arr1[idx] << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int n = 0; n < N; ++n)
        cin >> Arr1[n];

    fill(Arr2, Arr2 + 1001, 1);
    fill(Prev, Prev + 1001, -1);

    int ret = 1, idx = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (Arr1[j] < Arr1[i] && Arr2[i] < Arr2[j] + 1) {
                Arr2[i] = Arr2[j] + 1;
                Prev[i] = j;

                if (ret < Arr2[i]) {
                    ret = Arr2[i];
                    idx = i;
                }
            }
        }
    }

    cout << ret << '\n';
    go(idx);
    return 0;
}