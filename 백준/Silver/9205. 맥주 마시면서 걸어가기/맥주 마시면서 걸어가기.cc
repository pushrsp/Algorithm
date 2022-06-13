#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<pair<int, int>> store;
vector<bool> storeVisit;

int storeCnt = 0;
int startY = 0;
int startX = 0;
int destY = 0;
int destX = 0;

int dist(const pair<int, int> a, const pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void BFS() {
    queue<pair<int, int>> q;
    q.push({startY, startX});

    while (!q.empty()) {
        pair<int, int> pos = q.front();
        q.pop();

        if (dist(pos, {destY, destX}) <= 1000) {
            cout << "happy" << endl;
            return;
        }


        for (int i = 0; i < store.size(); ++i) {
            if (dist(pos, store[i]) <= 1000) {
                if (!storeVisit[i]) {
                    q.push(store[i]);
                    storeVisit[i] = true;
                }
            }
        }
    }

    cout << "sad" << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cin >> storeCnt;

        store = vector<pair<int, int>>(storeCnt, {0, 0});
        storeVisit = vector<bool>(storeCnt, false);

        cin >> startY >> startX;

        for (int j = 0; j < storeCnt; ++j) {
            cin >> store[j].first >> store[j].second;
        }

        cin >> destY >> destX;

        BFS();
    }
    return 0;
}