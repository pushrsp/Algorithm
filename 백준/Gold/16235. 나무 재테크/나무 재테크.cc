#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K;
vector<vector<int>> Map, Origin;
vector<vector<vector<int>>> Trees;
int deltaY[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int deltaX[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool CmpTree(const int &a, const int &b) {
    return a < b;
}

void SpringSummer() {
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (Trees[y][x].empty())
                continue;

            int dead = 0;
            vector<int> temp;
            sort(Trees[y][x].begin(), Trees[y][x].end(), CmpTree);
            for (auto &tree: Trees[y][x]) {
                if (tree > Map[y][x]) {
                    dead += tree / 2;
                    continue;
                }

                Map[y][x] -= tree;
                tree++;
                temp.push_back(tree);
            }

            Trees[y][x].clear();
            Trees[y][x] = temp;
            Map[y][x] += dead;
        }
    }
}

void Autumn() {
    vector<pair<int, int>> new_tree;

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            for (auto &tree: Trees[y][x]) {
                if (tree % 5)
                    continue;

                for (int i = 0; i < 8; ++i) {
                    int nextY = y + deltaY[i], nextX = x + deltaX[i];

                    if (nextY < 0 || nextY >= N)
                        continue;
                    if (nextX < 0 || nextX >= N)
                        continue;

                    Trees[nextY][nextX].push_back(1);
                }
            }
        }
    }
}

void Winter() {
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            Map[y][x] += Origin[y][x];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    Map = vector<vector<int>>(N, vector<int>(N, 5));
    Origin = vector<vector<int>>(N, vector<int>(N, 0));
    Trees = vector<vector<vector<int>>>(N, vector<vector<int>>(N));

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> Origin[y][x];
        }
    }

    for (int m = 0; m < M; ++m) {
        int y, x, z;
        cin >> y >> x >> z;

        y--, x--;
        Trees[y][x].push_back(z);
    }

    while (K--) {
        SpringSummer();
        Autumn();
        Winter();
    }

    int answer = 0;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            answer += Trees[y][x].size();
        }
    }

    cout << answer << '\n';
    return 0;
}