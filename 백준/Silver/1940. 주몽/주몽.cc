#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<int> Vec;

int main() {
    cin >> N >> M;

    Vec = vector<int>(N);
    for (int n = 0; n < N; ++n)
        cin >> Vec[n];


    if (M > 200000) {
        cout << 0 << endl;
    } else {
        int answer = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (Vec[i] + Vec[j] == M)
                    answer++;
            }
        }

        cout << answer << endl;
    }
    return 0;
}