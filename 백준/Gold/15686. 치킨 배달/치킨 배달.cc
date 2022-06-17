#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M, MAX = 22222222, answer = 22222222;
vector<vector<int>> adj;
vector<pair<int, int>> house, chicken, temp;
vector<bool> visited;

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

int get_dist() {
    int dist = 0;
    for (int i = 0; i < house.size(); ++i) {
        int houseY = house[i].first;
        int houseX = house[i].second;
        int D = MAX;

        for (int j = 0; j < M; ++j) {
            int chickenY = temp[j].first;
            int chickenX = temp[j].second;
            int d = abs(houseY - chickenY) + abs(houseX - chickenX);

            D = min(D, d);
        }
        dist += D;
    }

    return dist;
}

void comb(int idx, int cnt) {
    if (cnt == M) {
        answer = min(answer, get_dist());
        return;
    } else {
        for (int i = idx; i < chicken.size(); ++i) {
            if (visited[i])
                continue;

            visited[i] = true;
            temp.push_back(chicken[i]);
            comb(i, cnt + 1);
            visited[i] = false;
            temp.pop_back();
        }
    }
}

int main() {
    cin >> N >> M;

    adj = vector<vector<int>>(N, vector<int>(N));

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> adj[y][x];

            if (adj[y][x] == 1)
                house.emplace_back(y, x);
            else if (adj[y][x] == 2)
                chicken.emplace_back(y, x);
        }
    }

    visited = vector<bool>(chicken.size(), false);
    comb(0, 0);
    cout << answer << endl;
    return 0;
}