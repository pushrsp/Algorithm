#include <iostream>
#include <vector>
#include <queue>

using namespace std;

uint64_t A, B;

void BFS() {
    queue<pair<uint64_t, int>> q;
    q.push({A, 1});

    while (!q.empty()) {
        uint64_t n = q.front().first;
        int cnt = q.front().second;

        q.pop();

        if (n == B) {
            cout << cnt << endl;
            return;
        }

        for (int i = 0; i < 2; ++i) {
            uint64_t nextN;
            switch (i) {
                case 0:
                    nextN = n * 2;
                    break;
                case 1:
                    nextN = (n * 10) + 1;
                    break;
            }

            if (nextN > B)
                continue;

            q.push({nextN, cnt + 1});
        }
    }

    cout << -1 << endl;
}

int main() {
    cin >> A >> B;

    BFS();
    return 0;
}