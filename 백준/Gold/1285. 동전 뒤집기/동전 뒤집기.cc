#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, Map[21], Answer = INT32_MAX;

void go(int cnt) {
    if (cnt == N + 1) {
        int sum = 0;
        for (int i = 1; i <= (1 << (N - 1)); i *= 2) {
            int s = 0;
            for (int j = 1; j <= N; ++j) {
                if (i & Map[j])
                    s++;
            }

            sum += min(s, N - s);
        }

        Answer = min(Answer, sum);
        return;
    }

    Map[cnt] = ~Map[cnt];
    go(cnt + 1);
    Map[cnt] = ~Map[cnt];
    go(cnt + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int y = 1; y <= N; ++y) {
        string s;
        cin >> s;

        int value = 1;
        for (int x = 0; x < s.size(); ++x) {
            if (s[x] == 'T')
                Map[y] |= value;

            value *= 2;
        }
    }

    go(1);

    cout << Answer << '\n';
    return 0;
}