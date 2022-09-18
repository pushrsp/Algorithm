#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int y, x, cnt;
};

vector<vector<int>> BOARD;

//위 왼 아 오
int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};

int bfs(Node start, Node dest) {
    vector<vector<bool>> visited(4, vector<bool>(4, false));
    queue<Node> q;

    q.push(start);

    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        if (now.y == dest.y && now.x == dest.x)
            return now.cnt;

        //방향키
        for (int i = 0; i < 4; ++i) {
            int nextY = now.y + deltaY[i];
            int nextX = now.x + deltaX[i];

            if (nextY < 0 || nextY > 3)
                continue;
            if (nextX < 0 || nextX > 3)
                continue;

            if (!visited[nextY][nextX]) {
                visited[nextY][nextX] = true;
                q.push({nextY, nextX, now.cnt + 1});
            }

            for (int j = 0; j < 2; ++j) {
                if (BOARD[nextY][nextX] != 0)
                    break;
                if (nextY + deltaY[i] < 0 || nextY + deltaY[i] > 3)
                    break;
                if (nextX + deltaX[i] < 0 || nextX + deltaX[i] > 3)
                    break;

                nextY += deltaY[i];
                nextX += deltaX[i];
            }

            if (!visited[nextY][nextX]) {
                visited[nextY][nextX] = true;
                q.push({nextY, nextX, now.cnt + 1});
            }
        }
    }

    return INT32_MAX;
}

int dfs(Node node) {
    int ret = INT32_MAX;

    for (int i = 1; i <= 6; ++i) {
        vector<Node> cards;
        for (int y = 0; y < 4; ++y) {
            for (int x = 0; x < 4; ++x) {
                if (BOARD[y][x] == i)
                    cards.push_back({y, x, 0});
            }
        }

        if (cards.empty())
            continue;

        int n1 = bfs(node, cards[0]) + bfs(cards[0], cards[1]) + 2;
        int n2 = bfs(node, cards[1]) + bfs(cards[1], cards[0]) + 2;

        for (auto &card: cards)
            BOARD[card.y][card.x] = 0;

        ret = min(ret, n1 + dfs(cards[1]));
        ret = min(ret, n2 + dfs(cards[0]));

        for (auto &card: cards)
            BOARD[card.y][card.x] = i;
    }

    if (ret == INT32_MAX)
        return 0;

    return ret;
}

int solution(vector<vector<int>> board, int r, int c) {
    BOARD = board;

    int answer = dfs({r, c, 0});
    return answer;
}