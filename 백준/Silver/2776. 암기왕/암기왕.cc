#include <iostream>
#include <unordered_map>

using namespace std;

int T, N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--) {
        cin >> N;

        unordered_map<int, bool> um;
        for (int n = 0; n < N; ++n) {
            int a;
            cin >> a;

            um[a] = true;
        }

        cin >> M;
        for (int m = 0; m < M; ++m) {
            int b;
            cin >> b;

            cout << um[b] << '\n';
        }
    }
    return 0;
}