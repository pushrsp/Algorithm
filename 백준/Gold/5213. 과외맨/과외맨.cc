#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define INF 987654321
#define MAX 501

using namespace std;

struct Point {
    int y, x, team;
};

struct Tile {
    int value = INF, team = INF;
};

int N, History[MAX * MAX], Team = 1;
vector<vector<Tile>> Map;
vector<vector<int>> Dist;
int DY[4] = {-1, 0, 1, 0}, DX[4] = {0, -1, 0, 1};

bool InRange(int nowY, int nowX) {
    return 1 <= nowY && nowY <= N && 1 <= nowX && nowX <= N * 2;
}

void Fill() {
    for (int &history: History)
        history = INF;
}

void IfOdd(int nowY) {
    for (int i = 1; i <= N * 2; i += 2) {
        int a, b;
        cin >> a >> b;

        Map[nowY][i].value = a, Map[nowY][i + 1].value = b;
        Map[nowY][i].team = Team, Map[nowY][i + 1].team = Team;
        Team++;
    }
}

void IfEven(int nowY) {
    for (int i = 2; i <= 2 * N - 1; i += 2) {
        int a, b;
        cin >> a >> b;

        Map[nowY][i].value = a, Map[nowY][i + 1].value = b;
        Map[nowY][i].team = Team, Map[nowY][i + 1].team = Team;
        Team++;
    }
}

void Di() {
    queue<Point> pq;

    Dist[1][1] = 1;
    Dist[1][2] = 1;
    History[1] = 1;
    pq.push({1, 1, Map[1][1].team});
    pq.push({1, 2, Map[1][2].team});

    int dest = 1;
    while (!pq.empty()) {
        auto now = pq.front();
        pq.pop();

        dest = max(dest, now.team);
        if (now.team == Team - 1)
            break;

        for (int i = 0; i < 4; ++i) {
            int nextY = now.y + DY[i], nextX = now.x + DX[i];

            if (!InRange(nextY, nextX))
                continue;
            if (Map[nextY][nextX].value == INF || Map[nextY][nextX].team == INF)
                continue;
            if (Dist[nextY][nextX] != 0)
                continue;

            if (Map[nextY][nextX].team != now.team && Map[nextY][nextX].value == Map[now.y][now.x].value) {
                pq.push({nextY, nextX, Map[nextY][nextX].team});
                Dist[nextY][nextX] = Dist[now.y][now.x] + 1;
                History[Map[nextY][nextX].team] = now.team;

                if (Map[nextY][nextX - 1].team == Map[nextY][nextX].team) {
                    Dist[nextY][nextX - 1] = Dist[now.y][now.x] + 1;
                    pq.push({nextY, nextX - 1, Map[nextY][nextX].team});
                } else if (Map[nextY][nextX + 1].team == Map[nextY][nextX].team) {
                    Dist[nextY][nextX + 1] = Dist[now.y][now.x] + 1;
                    pq.push({nextY, nextX + 1, Map[nextY][nextX].team});
                }
            }
        }
    }

    stack<int> st;
    int dist = 1;

    while (History[dest] != dest) {
        st.push(dest);
        dist += 1;
        dest = History[dest];
    }
    st.push(1);

    cout << dist << '\n';
    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    Map = vector<vector<Tile>>(N + 1, vector<Tile>((N * 2) + 1));
    Dist = vector<vector<int>>(N + 1, vector<int>((N * 2) + 1));

    Fill();
    for (int i = 1; i <= N; ++i) {
        if (i % 2)
            IfOdd(i);
        else
            IfEven(i);
    }

    Di();
    return 0;
}