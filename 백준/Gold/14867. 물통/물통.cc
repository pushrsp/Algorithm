#include <iostream>
#include <queue>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int A, B, C, D;

struct Water {
    int a, b, count;
};

void push(int a, int b, int count, set<pair<int, int>> &s, queue<Water> &q) {
    if (s.find({a, b}) != s.end())
        return;

    s.insert({a, b});
    q.push({a, b, count});
}

int bfs(int a, int b) {
    queue<Water> q;
    set<pair<int, int>> s;

    q.push({a, b, 0});
    s.insert({a, b});

    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        if (now.a == C && now.b == D)
            return now.count;

        //fill
        push(A, now.b, now.count + 1, s, q);
        push(now.a, B, now.count + 1, s, q);

        //empty
        push(now.a, 0, now.count + 1, s, q);
        push(0, now.b, now.count + 1, s, q);

        //move
        push(min(now.a + now.b, A), max(0, now.a + now.b - A), now.count + 1, s, q);
        push(max(0, now.a + now.b - B), min(now.a + now.b, B), now.count + 1, s, q);
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C >> D;
    cout << bfs(0, 0) << '\n';
    return 0;
}