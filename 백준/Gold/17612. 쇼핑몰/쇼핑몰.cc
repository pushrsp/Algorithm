#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define ll long long

using namespace std;

struct Counter {
    int index, time;

    bool operator<(const Counter other) const {
        if (time == other.time)
            return index > other.index;

        return time > other.time;
    }
};

struct Exit {
    int index, time;
    ll id;

    bool operator<(const Exit other) const {
        if (time == other.time)
            return index < other.index;

        return time > other.time;
    }
};

int N, K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    priority_queue<Counter> counter;
    for (int k = 1; k <= K; ++k)
        counter.push({k, 0});

    priority_queue<Exit> exit;
    int id, w;
    for (int n = 0; n < N; ++n) {
        cin >> id >> w;

        auto curr = counter.top();
        counter.pop();

        exit.push({curr.index, curr.time + w, id});
        counter.push({curr.index, curr.time + w});
    }
    
    ll ret = 0, start = 1;
    while (!exit.empty()) {
        ret += exit.top().id * start;
        exit.pop();
        start++;
    }

    cout << ret << '\n';

    return 0;
}