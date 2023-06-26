#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int ADDH, ADDT, MINT, ADDO, MINO, time;
};

int T, N;
bool Visited[61];
Point Points[61];

void push(queue<Point> &q, Point &curr) {
    q.push({curr.ADDH, curr.ADDT, curr.MINT, curr.ADDO, curr.MINO + 1, curr.time - 1});
    q.push({curr.ADDH, curr.ADDT, curr.MINT, curr.ADDO + 1, curr.MINO, curr.time + 1});
    q.push({curr.ADDH, curr.ADDT, curr.MINT + 1, curr.ADDO, curr.MINO, curr.time - 10});
    q.push({curr.ADDH, curr.ADDT + 1, curr.MINT, curr.ADDO, curr.MINO, curr.time + 10});
    q.push({curr.ADDH + 1, curr.ADDT, curr.MINT, curr.ADDO, curr.MINO, curr.time + 60});
}

void bfs() {
    queue<Point> q;
    q.push({0, 0, 0, 0, 0, 0});

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        if (curr.time >= 0 && curr.time <= 60 && !Visited[curr.time]) {
            Visited[curr.time] = true;
            Points[curr.time] = curr;

            push(q, curr);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    bfs();

    cin >> T;
    while (T--) {
        cin >> N;
        int d = N / 60, r = N % 60;

        cout << Points[r].ADDH + d << ' '
             << Points[r].ADDT << ' '
             << Points[r].MINT << ' '
             << Points[r].ADDO << ' '
             << Points[r].MINO << '\n';
    }
    return 0;
}