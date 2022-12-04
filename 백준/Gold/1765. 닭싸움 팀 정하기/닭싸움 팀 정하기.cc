#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N, M, Discovered[1001];
vector<pair<char, int>> Students[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    cin >> M;

    for (int i = 0; i < M; ++i) {
        char c;
        int a, b;

        cin >> c >> a >> b;

        Students[a].emplace_back(c, b);
        Students[b].emplace_back(c, a);
    }

    int answer = 0;
    for (int i = 1; i <= N; ++i) {
        if (Discovered[i] != 1)
            answer++;

        Discovered[i] = 1;

        for (auto &student: Students[i]) {
            if (student.first == 'E') {
                for (auto &ee: Students[student.second]) {
                    if (Discovered[ee.second] == 0 && ee.first == 'E')
                        Discovered[ee.second] = 1;
                }
            } else {
                if (Discovered[student.second] == 0)
                    Discovered[student.second] = 1;

                for (auto &ff: Students[student.second]) {
                    if (Discovered[ff.second] == 0 && ff.first == 'F')
                        Discovered[ff.second] = 1;
                }
            }
        }
    }

    cout << answer << '\n';
    return 0;
}