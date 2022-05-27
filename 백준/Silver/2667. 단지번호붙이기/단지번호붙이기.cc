#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define MAX 25

using namespace std;

int house[MAX][MAX];
bool visited[MAX][MAX];
int N;
int cnt = 0;
vector<int> result;

class Pos {
public:
    Pos(int y, int x) : Y(y), X(x) {

    }

public:
    int Y;
    int X;
};

void BFS(int y, int x) {
    //위 왼쪽 아래 오른쪽
    int deltaY[4] = {-1, 0, 1, 0};
    int deltaX[4] = {0, -1, 0, 1};

    queue<Pos *> q;

    visited[y][x] = true;
    q.push(new Pos(y, x));

    cnt++;

    while (!q.empty()) {
        Pos *pos = q.front();
        q.pop();

        int nowY = pos->Y;
        int nowX = pos->X;

        for (int i = 0; i < 4; ++i) {
            int nextY = nowY + deltaY[i];
            int nextX = nowX + deltaX[i];

            if (0 <= nextY && nextY < N && 0 <= nextX && nextX < N) {
                if (house[nextY][nextX] == 1 && !visited[nextY][nextX]) {
                    visited[nextY][nextX] = true;
                    q.push(new Pos(nextY, nextX));
                    cnt++;
                }
            }
        }
    }
}

int main() {
    cin >> N;

    for (int y = 0; y < N; ++y) {
        string a;
        cin >> a;

        for (int x = 0; x < a.length(); ++x) {
            char t = a[x];
            int c = t - '0';

            house[y][x] = c;
        }
    }

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (house[y][x] == 1 && !visited[y][x]) {
                cnt = 0;
                BFS(y, x);
                result.push_back(cnt);
            }
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << endl;
    for (int a: result) {
        cout << a << endl;
    }

    return 0;
}