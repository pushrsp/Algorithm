#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> adj;

int pull(int _y, int _x) {
    vector<int> answer;

    for (int y = _y; y < _y + 2; ++y) {
        for (int x = _x; x < _x + 2; ++x) {
            answer.push_back(adj[y][x]);
        }
    }

    sort(answer.begin(), answer.end());
    return answer[2];
}

int main() {
    cin >> N;
    adj = vector<vector<int>>(N, vector<int>(N));

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> adj[y][x];
        }
    }

    while (N > 1) {
        for (int y = 0; y < N; y += 2) {
            for (int x = 0; x < N; x += 2) {
                adj[y / 2][x / 2] = pull(y, x);
            }
        }
        N /= 2;
    }

    cout << adj[0][0] << endl;
    return 0;
}