#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

int Y, X;

vector<string> adj;
vector<vector<bool>> visited;

struct Pos {
public:
    Pos operator+(const Pos &other) const {
        Pos ret{y + other.y, x + other.x};

        return ret;
    }

    bool operator==(const Pos &other) const {
        return y == other.y && x == other.x;
    }

    bool operator<(const Pos &other) const {
        if (y != other.y)
            return y < other.y;

        return x < other.x;
    }

public:
    int y;
    int x;
};

void BFS(Pos pos) {
    queue<Pos> q;
    map<Pos, Pos> parent;

    Pos delta[4] = {
            Pos{-1, 0}, //위
            Pos{0, -1}, //왼쪽
            Pos{1, 0}, //아래
            Pos{0, 1}, //오른쪽
    };

    q.push(pos);
    parent[pos] = pos;
    visited[pos.y][pos.x] = true;

    Pos dest{Y - 1, X - 1};

    while (!q.empty()) {
        pos = q.front();
        q.pop();

        if (pos == dest)
            break;

        for (auto i: delta) {
            Pos nextPos = pos + i;

            if (nextPos.y < 0 || nextPos.y > Y - 1)
                continue;
            if (nextPos.x < 0 || nextPos.x > X - 1)
                continue;
            if (adj[nextPos.y][nextPos.x] == '0')
                continue;
            if (visited[nextPos.y][nextPos.x])
                continue;

            q.push(nextPos);
            visited[nextPos.y][nextPos.x] = true;
            parent[nextPos] = pos;
        }
    }

    vector<Pos> _path;
    _path.clear();

    pos = dest;

    while (true) {
        _path.push_back(pos);

        if (parent[pos] == pos)
            break;

        pos = parent[pos];
    }

    cout << _path.size() << endl;
}

int main() {
    cin >> Y >> X;
    for (int i = 0; i < Y; ++i) {
        string a;
        cin >> a;

        adj.push_back(a);
    }

    visited = vector<vector<bool>>(Y, vector<bool>(X, false));
    Pos pos{0, 0};

    BFS(pos);
    
    return 0;
}