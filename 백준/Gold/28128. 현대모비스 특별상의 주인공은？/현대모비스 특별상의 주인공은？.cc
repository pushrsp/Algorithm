#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    vector<vector<string>> vec(N, vector<string>(M));
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            cin >> vec[y][x];
        }
    }

    set<string> answer;
    for (int y = 0; y < N - 1; ++y) {
        for (int x = 0; x < M; ++x) {
            if (vec[y][x] == vec[y + 1][x])
                answer.insert(vec[y][x]);
        }
    }

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M - 1; ++x) {
            if (vec[y][x] == vec[y][x + 1])
                answer.insert(vec[y][x]);
        }
    }

    for (int y = 0; y < N - 2; ++y) {
        for (int x = 0; x < M; ++x) {
            if (vec[y][x] == vec[y + 2][x])
                answer.insert(vec[y][x]);
        }
    }

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M - 2; ++x) {
            if (vec[y][x] == vec[y][x + 2])
                answer.insert(vec[y][x]);
        }
    }

    if (answer.empty()) {
        cout << "MANIPULATED";
    } else {
        for (auto &s: answer)
            cout << s << '\n';
    }
    return 0;
}