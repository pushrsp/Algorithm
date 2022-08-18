#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, T, P;

int get_dist(vector<vector<vector<bool>>> &seats, int hour, int mins, int idx) {
    int minDist = 101;

    for (int i = 0; i < N; ++i) {
        if (i == idx)
            continue;

        if (seats[i][hour][mins])
            minDist = min(minDist, abs(idx - i));
    }

    return minDist;
}

int find_seat(vector<vector<vector<bool>>> &seats, int hour, int mins) {
    int idx = 0;
    int maxDist = 0;

    for (int i = 0; i < N; ++i) {
        if (!seats[i][hour][mins]) {
            int dist = get_dist(seats, hour, mins, i);

            if (dist > maxDist) {
                maxDist = dist;
                idx = i;
            }
        }
    }

    return idx;
}

int get_hour(int time) {
    return time / 100;
}

int get_min(int time) {
    int hour = get_hour(time);

    return time - (hour * 100);
}

int main() {
    cin >> N >> T >> P;

    vector<vector<vector<bool>>> seats(N, vector<vector<bool>>(22, vector<bool>(60, false)));
    vector<pair<int, int>> reserve(T);

    for (int t = 0; t < T; ++t)
        cin >> reserve[t].first >> reserve[t].second;

    sort(reserve.begin(), reserve.end());

    for (int t = 0; t < T; ++t) {
        int startHour = get_hour(reserve[t].first);
        int startMin = get_min(reserve[t].first);
        int endHour = get_hour(reserve[t].second);
        int endMin = get_min(reserve[t].second);

        int seat = find_seat(seats, startHour, startMin);
        if (startHour == endHour) {
            for (int i = startMin; i < endMin; ++i)
                seats[seat][startHour][i] = true;
        } else {
            for (int i = startMin; i < 60; ++i)
                seats[seat][startHour][i] = true;

            for (int i = startHour + 1; i < endHour; ++i) {
                for (int j = 0; j < 60; ++j)
                    seats[seat][i][j] = true;
            }

            for (int i = 0; i < endMin; ++i)
                seats[seat][endHour][i] = true;
        }
    }

    int cnt = 0;
    for (int i = 9; i <= 20; ++i) {
        for (int j = 0; j < 60; ++j) {
            if (!seats[P - 1][i][j])
                cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}