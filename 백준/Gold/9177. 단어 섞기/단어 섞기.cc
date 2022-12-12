#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct Point {
    int l, r, f;
};

int T;
string A, B, C;
bool Visited[201][201];

/**
1
cat tree tcraete
 */

bool bfs() {
    queue<Point> q;

    q.push({0,0,0});
    Visited[0][0]=true;

    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        if(now.f == C.length())
            return true;

        if(now.l < A.length() && A[now.l] == C[now.f] && !Visited[now.l + 1][now.r]) {
            Visited[now.l +1][now.r] = true;
            q.push({now.l + 1, now.r, now.f + 1});
        }

        if(now.r < B.length() && B[now.r] == C[now.f] && !Visited[now.l][now.r + 1]) {
            Visited[now.l][now.r + 1] = true;
            q.push({now.l, now.r + 1, now.f + 1});
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; ++i) {
        cin >> A >> B >> C;

        cout << "Data set " << i + 1 << ':';
        if(C[0] != A[0] && C[0] != B[0]) {
            cout << " no" << '\n';
            continue;
        }

        if(bfs())
            cout << " yes" << '\n';
        else
            cout << " no" << '\n';

        ::memset(Visited, false, sizeof(Visited));
    }
    return 0;
}