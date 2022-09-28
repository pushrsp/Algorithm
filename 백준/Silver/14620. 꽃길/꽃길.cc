#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, Answer = INT32_MAX;
vector<vector<int>> Map;
vector<vector<bool>> Visited;

void dfs(int cnt, int price) {
    if (cnt == 3) {
        Answer = min(Answer, price);
        return;
    }

    for (int y = 1; y <= N - 2; ++y) {
        for (int x = 1; x <= N - 2; ++x) {
            if (Visited[y][x] || Visited[y - 1][x] || Visited[y][x - 1] || Visited[y + 1][x] || Visited[y][x + 1])
                continue;

            int p = price;
            Visited[y][x] = true; //중심
            Visited[y - 1][x] = true; // 위
            Visited[y][x - 1] = true; // 왼
            Visited[y + 1][x] = true; // 아
            Visited[y][x + 1] = true; // 오

            p += Map[y][x];
            p += Map[y - 1][x];
            p += Map[y][x - 1];
            p += Map[y + 1][x];
            p += Map[y][x + 1];

            dfs(cnt + 1, p);

            Visited[y][x] = false;
            Visited[y - 1][x] = false; // 위
            Visited[y][x - 1] = false; // 왼
            Visited[y + 1][x] = false; // 아
            Visited[y][x + 1] = false; // 오
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    Map = vector<vector<int>>(N, vector<int>(N, 0));
    Visited = vector<vector<bool>>(N, vector<bool>(N, false));

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> Map[y][x];
        }
    }

    dfs(0, 0);
    cout << Answer << '\n';
    return 0;
}