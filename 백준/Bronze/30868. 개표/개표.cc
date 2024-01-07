#include <iostream>
#include <map>
#include <algorithm>

#define INF 987654321

using namespace std;

int T, N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;

        int plus = N / 5, bar = N % 5;
        for (int p = 0; p < plus; ++p)
            cout << "++++ ";

        for (int b = 0; b < bar; ++b)
            cout << "|";

        cout << '\n';
    }

    return 0;
}