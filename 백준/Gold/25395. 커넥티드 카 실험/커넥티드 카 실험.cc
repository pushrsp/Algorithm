#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

struct Car {
    int i, x, h;
};

int N, S;
bool Visited[1000001];

bool asc(const Car &a, const Car &b) {
    return a.x < b.x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> S;

    vector<Car> cars(N + 1);
    for (int n = 1; n <= N; ++n)
        cin >> cars[n].x;
    for (int n = 1; n <= N; ++n)
        cin >> cars[n].h;
    for (int n = 1; n <= N; ++n)
        cars[n].i = n;

    sort(cars.begin(), cars.end(), asc);

    queue<Car> q;

    Visited[S] = true;
    q.push(cars[S]);

    while (!q.empty()) {
        int curr_idx = q.front().i;
        int curr_x = q.front().x;
        int curr_h = q.front().h;
        q.pop();

        for (int i = curr_idx; i >= 1; i--) {
            if (cars[i].x < curr_x - curr_h)
                break;
            if (Visited[cars[i].i])
                continue;

            Visited[cars[i].i] = true;
            q.push(cars[i]);
        }

        for (int i = curr_idx; i <= N; i++) {
            if (cars[i].x > curr_x + curr_h)
                break;
            if (Visited[cars[i].i])
                continue;

            Visited[cars[i].i] = true;
            q.push(cars[i]);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (Visited[i])
            cout << i << ' ';
    }

    return 0;
}