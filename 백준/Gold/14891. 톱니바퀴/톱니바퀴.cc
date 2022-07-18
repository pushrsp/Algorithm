#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int K;
vector<vector<int>> WHEEL(4);
queue<pair<int, int>> ORDER;

void clock_wise(int idx) {
    WHEEL[idx] = {
            WHEEL[idx][7], WHEEL[idx][0],
            WHEEL[idx][1], WHEEL[idx][2],
            WHEEL[idx][3], WHEEL[idx][4],
            WHEEL[idx][5], WHEEL[idx][6]
    };
}

void counter_clock_wise(int idx) {
    WHEEL[idx] = {
            WHEEL[idx][1], WHEEL[idx][2],
            WHEEL[idx][3], WHEEL[idx][4],
            WHEEL[idx][5], WHEEL[idx][6],
            WHEEL[idx][7], WHEEL[idx][0]
    };
}

vector<int> rotate_others(int pivot, int dir) {
    vector<int> rotate(4, 0);

    switch (pivot) {
        case 0:
            rotate[0] = dir;

            if (WHEEL[0][2] != WHEEL[1][6])
                rotate[1] = rotate[0] * -1;

            if (rotate[1] != 0 && WHEEL[1][2] != WHEEL[2][6])
                rotate[2] = rotate[1] * -1;

            if (rotate[2] != 0 && WHEEL[2][2] != WHEEL[3][6])
                rotate[3] = rotate[2] * -1;

            break;
        case 1:
            rotate[1] = dir;

            if (WHEEL[0][2] != WHEEL[1][6])
                rotate[0] = rotate[1] * -1;

            if (WHEEL[1][2] != WHEEL[2][6])
                rotate[2] = rotate[1] * -1;

            if (rotate[2] != 0 && WHEEL[2][2] != WHEEL[3][6])
                rotate[3] = rotate[2] * -1;

            break;
        case 2:
            rotate[2] = dir;

            if (WHEEL[1][2] != WHEEL[2][6])
                rotate[1] = rotate[2] * -1;

            if (rotate[1] != 0 && WHEEL[1][6] != WHEEL[0][2])
                rotate[0] = rotate[1] * -1;

            if (WHEEL[3][6] != WHEEL[2][2])
                rotate[3] = rotate[2] * -1;

            break;
        case 3:
            rotate[3] = dir;

            if (WHEEL[3][6] != WHEEL[2][2])
                rotate[2] = rotate[3] * -1;

            if (rotate[2] != 0 && WHEEL[2][6] != WHEEL[1][2])
                rotate[1] = rotate[2] * -1;

            if (rotate[1] != 0 && WHEEL[1][6] != WHEEL[0][2])
                rotate[0] = rotate[1] * -1;

            break;
    }

    return rotate;
}

int main() {
    for (int i = 0; i < 4; ++i) {
        string s;
        cin >> s;

        for (char j: s)
            WHEEL[i].push_back(j - '0');
    }

    cin >> K;
    for (int k = 0; k < K; ++k) {
        int idx, dir;
        cin >> idx >> dir;

        ORDER.push({idx, dir});
    }

    while (!ORDER.empty()) {
        auto order = ORDER.front();
        ORDER.pop();

        vector<int> rotate = rotate_others(order.first - 1, order.second);
        for (int r = 0; r < rotate.size(); ++r) {
            if (rotate[r] == 1) {
                clock_wise(r);
            } else if (rotate[r] == -1) {
                counter_clock_wise(r);
            }
        }
    }

    int sum = 0;
    int score = 1;
    for (int i = 0; i < 4; ++i) {
        if (WHEEL[i][0] == 1)
            sum += score;

        score *= 2;
    }

    cout << sum << endl;
    return 0;
}