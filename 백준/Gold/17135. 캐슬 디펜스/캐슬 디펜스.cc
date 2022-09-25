#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pos {
    int y, x, dist;
};

int N, M, D, Cnt = 3;

int answer = 0;
vector<int> Archer;
vector<vector<int>> Map;
vector<pair<int, int>> Enemy;

bool cmp_pos(const Pos &a, const Pos &b) {
    if (a.dist == b.dist)
        return a.x < b.x;

    return a.dist < b.dist;
}

vector<Pos> get_enemy(int startY, int startX, vector<pair<int, int>> &enemy) {
    vector<Pos> enemies;

    for (auto &enm: enemy) {
        int dist = abs(startY - enm.first) + abs(startX - enm.second);
        if (dist > D)
            continue;

        enemies.push_back({enm.first, enm.second, dist});
    }

    sort(enemies.begin(), enemies.end(), cmp_pos);

    return enemies;
}

void solve() {
    vector<pair<int, int>> enemy(Enemy);
    int sum = 0;

    while (!enemy.empty()) {
        vector<Pos> target;
        vector<vector<bool>> visited(N, vector<bool>(M, false));

        for (int archer: Archer) {
            vector<Pos> candidates = get_enemy(N, archer, enemy);
            if (candidates.empty())
                continue;

            if (!visited[candidates[0].y][candidates[0].x]) {
                target.push_back(candidates[0]);
                visited[candidates[0].y][candidates[0].x] = true;
            }
        }

        sum += target.size();
        vector<pair<int, int>> enem;
        for (auto &e: enemy) {
            bool remove = false;
            for (auto &t: target) {
                if (e.first == t.y && e.second == t.x)
                    remove = true;
            }

            if (!remove) {
                int nextY = e.first + 1;
                if (nextY < N)
                    enem.emplace_back(nextY, e.second);
            }
        }

        enemy = enem;
    }

    answer = max(answer, sum);
}

void dfs(int cnt, int idx) {
    if (cnt == Cnt) {
        solve();
        return;
    }

    for (int i = idx; i < M; ++i) {
        Archer.push_back(i);
        dfs(cnt + 1, i + 1);
        Archer.pop_back();
    }
}

int main() {
    cin >> N >> M >> D;

    Map = vector<vector<int>>(N, vector<int>(M, 0));
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            cin >> Map[y][x];

            if (Map[y][x])
                Enemy.emplace_back(y, x);
        }
    }

    dfs(0, 0);
    cout << answer << endl;
    return 0;
}