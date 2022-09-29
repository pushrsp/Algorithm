#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;

vector<vector<int>> Map1;

int main() {
    cin >> N >> M;

    Map1 = vector<vector<int>>(N, vector<int>(M));
    for (int y = 0; y < N; ++y) {
        string s;
        cin >> s;

        for (int x = 0; x < s.length(); ++x)
            Map1[y][x] = s[x] - '0';
    }

    int answer = 0;
    for (int i = 0; i < 1 << (N * M); ++i) {
        int sum = 0;

        for (int y = 0; y < N; ++y) {
            int num = 0;

            for (int x = 0; x < M; ++x) {
                int d1 = y * M + x;

                if (i & (1 << d1)) {
                    sum += num;
                    num = 0;
                } else {
                    num = num * 10 + Map1[y][x];
                }
            }
            sum += num;
        }

        for (int x = 0; x < M; ++x) {
            int num = 0;

            for (int y = 0; y < N; ++y) {
                int d1 = y * M + x;

                if (i & (1 << d1)) {
                    num = num * 10 + Map1[y][x];
                } else {
                    sum += num;
                    num = 0;
                }
            }

            sum += num;
        }

        answer = max(answer, sum);
    }

    cout << answer << '\n';
    return 0;
}