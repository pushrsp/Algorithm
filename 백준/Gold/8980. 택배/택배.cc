#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Box {
    int from, to, count;

    bool operator<(const Box &other) const {
        if (to == other.to)
            return from < other.from;

        return to < other.to;
    }
};

int N, C, M;
Box arr[10001] = {};
int mass[10001] = {0};

int main() {
    cin >> N >> C >> M;

    for (int m = 0; m < M; ++m)
        cin >> arr[m].from >> arr[m].to >> arr[m].count;

    sort(arr, arr + M);

    int answer = 0;
    for (int m = 0; m < M; ++m) {
        int count = 0;

        for (int i = arr[m].from; i < arr[m].to; ++i)
            count = max(mass[i], count);

        int v = min(arr[m].count, C - count);
        answer += v;

        for (int i = arr[m].from; i < arr[m].to; ++i)
            mass[i] += v;
    }

    cout << answer << endl;

    return 0;
}