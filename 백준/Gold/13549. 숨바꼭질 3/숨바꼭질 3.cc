#include <iostream>
#include <vector>
#include <queue>
#include <set>

#define MAX 100000
#define ll long long

using namespace std;

int N, K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    set<int> visited;

    pq.emplace(0, N);
    visited.insert(N);

    int answer = INT32_MAX;
    while (!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        if (now.second == K) {
            cout << now.first << '\n';
            return 0;
        }

        if (now.second * 2 <= MAX && visited.find(now.second * 2) == visited.end()) {
            visited.insert(now.second * 2);
            pq.emplace(now.first, now.second * 2);
        }

        if (now.second + 1 <= MAX && visited.find(now.second + 1) == visited.end()) {
            visited.insert(now.second + 1);
            pq.emplace(now.first + 1, now.second + 1);
        }

        if (now.second - 1 >= 0 && visited.find(now.second - 1) == visited.end()) {
            visited.insert(now.second - 1);
            pq.emplace(now.first + 1, now.second - 1);
        }
    }

    cout << answer << '\n';

    return 0;
}