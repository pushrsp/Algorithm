#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Delivery {
    int from, to, count;

    bool operator<(const Delivery &other) const {
        if (to == other.to)
            return from > other.from;

        return to > other.to;
    }
};

int N, C, M;

int main() {
    cin >> N >> C >> M;

    vector<int> villages(N + 1, 0);
    priority_queue<Delivery> pq;
    for (int m = 0; m < M; ++m) {
        int from, to, count;
        cin >> from >> to >> count;

        pq.push({from, to, count});
    }

    int answer = 0;
    while (!pq.empty()) {
        Delivery delivery = pq.top();
        pq.pop();

        int c = 0;
        for (int i = delivery.from; i < delivery.to; ++i) {
            if (villages[i] > c)
                c = villages[i];
        }

        int count = min(delivery.count, C - c);
        answer += count;

        for (int i = delivery.from; i < delivery.to; ++i) {
            villages[i] += count;
        }
    }

    cout << answer << endl;
    return 0;
}