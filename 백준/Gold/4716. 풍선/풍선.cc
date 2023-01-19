#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include <algorithm>

#define ll long long
#define MAX 1001
#define INF 987654321

using namespace std;

struct Team {
    int b, da, db;

    bool operator<(const Team &other) const {
        return ::abs(da - db) < ::abs(other.da - other.db);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (true) {
        int N, A, B;
        cin >> N >> A >> B;

        if (N == 0 && A == 0 && B == 0)
            break;

        priority_queue<Team> pq;
        int b, da, db;
        for (int i = 0; i < N; ++i) {
            cin >> b >> da >> db;
            pq.push({b, da, db});
        }

        int ret = 0;
        while (!pq.empty()) {
            auto now = pq.top();
            pq.pop();

            if (now.da < now.db) {
                if (A - now.b < 0) {
                    ret += A * now.da;
                    now.b -= A;
                    A = 0;

                    ret += now.b * now.db;
                    B -= now.b;
                } else {
                    A -= now.b;
                    ret += now.b * now.da;
                }
            } else {
                if (B - now.b < 0) {
                    ret += B * now.db;
                    now.b -= B;
                    B = 0;

                    ret += now.b * now.da;
                    A -= now.b;
                } else {
                    B -= now.b;
                    ret += now.b * now.db;
                }
            }
        }

        cout << ret << '\n';
    }

    return 0;
}