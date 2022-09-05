#include <iostream>
#include <vector>

using namespace std;

struct FIREBALL {
    int y, x;
    int m, s, d;
};

int N, M, K;

int dy[8] = {-1, -1, 0, +1, +1, +1, 0, -1};
int dx[8] = {0, +1, +1, +1, 0, -1, -1, -1};

vector<FIREBALL> ball;
vector<int> map[50][50];

void move() {
    vector<int> new_map[50][50];
    for (int i = 0; i < ball.size(); i++) {
        int dir = ball[i].d;
        int speed = ball[i].s % N;

        int ny = (ball[i].y + (dy[dir] * speed) + N) % N;
        int nx = (ball[i].x + (dx[dir] * speed) + N) % N;
        new_map[ny][nx].push_back(i);

        ball[i].y = ny;
        ball[i].x = nx;
    }

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            map[y][x] = new_map[y][x];
        }
    }
}

void sum() {
    vector<FIREBALL> new_ball;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (map[y][x].empty())
                continue;

            if (map[y][x].size() == 1) {
                int idx = map[y][x][0];
                new_ball.push_back(ball[idx]);
            } else {
                int sum_m = 0, sum_s = 0;

                bool odd = true, even = true;
                for (int i = 0; i < map[y][x].size(); ++i) {
                    int idx = map[y][x][i];

                    sum_m += ball[idx].m;
                    sum_s += ball[idx].s;

                    if (ball[idx].d % 2 == 0)
                        odd = false;
                    else
                        even = false;
                }

                if (sum_m / 5 == 0)
                    continue;

                int cur_m = sum_m / 5, cur_s = sum_s / map[y][x].size();
                for (int i = 0; i < 4; ++i) {
                    if (odd || even)
                        new_ball.push_back({y, x, cur_m, cur_s, i * 2});
                    else
                        new_ball.push_back({y, x, cur_m, cur_s, i * 2 + 1});

                }
            }
        }
    }

    ball = new_ball;
}

int solve() {
    while (K--) {
        move();
        sum();
    }

    int answer = 0;
    for (FIREBALL &fireball: ball)
        answer += fireball.m;

    return answer;
}

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < M; ++i) {
        int y, x, m, s, d;
        cin >> y >> x >> m >> s >> d;

        y -= 1;
        x -= 1;

        ball.push_back({y, x, m, s, d});
        map[y][x].push_back(i);
    }

    cout << solve() << endl;
    return 0;
}