#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

vector<int> arr[33] = {
        {0,  1,  2,  3,  4,  5}, // 시작
        {2,  2,  3,  4,  5,  6},
        {4,  3,  4,  5,  6,  7},
        {6,  4,  5,  6,  7,  8},
        {8,  5,  6,  7,  8,  9},
        {10, 21, 22, 23, 24, 30},
        {12, 7,  8,  9,  10, 11},
        {14, 8,  9,  10, 11, 12},
        {16, 9,  10, 11, 12, 13},
        {18, 10, 11, 12, 13, 14},
        {20, 25, 26, 24, 30, 31},
        {22, 12, 13, 14, 15, 16},
        {24, 13, 14, 15, 16, 17},
        {26, 14, 15, 16, 17, 18},
        {28, 15, 16, 17, 18, 19},
        {30, 27, 28, 29, 24, 30},
        {32, 17, 18, 19, 20, 32},
        {34, 18, 19, 20, 32, 32},
        {36, 19, 20, 32, 32, 32},
        {38, 20, 32, 32, 32, 32},
        {40, 32, 32, 32, 32, 32},
        {13, 22, 23, 24, 30, 31},
        {16, 23, 24, 30, 31, 20},
        {19, 24, 30, 31, 20, 32},
        {25, 30, 31, 20, 32, 32},
        {22, 26, 24, 30, 31, 20},
        {24, 24, 30, 31, 20, 32},
        {28, 28, 29, 24, 30, 31},
        {27, 29, 24, 30, 31, 20},
        {26, 24, 30, 31, 20, 32},
        {30, 31, 20, 32, 32, 32},
        {35, 20, 32, 32, 32, 32},
        {0,  32, 32, 32, 32, 32}, // 끝
};
vector<int> Move(10), Horse(4);
int Answer = -1;

void go(int idx, int score) {
    if (idx == 10) {
        Answer = max(Answer, score);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        //현재 포지션 가져오기
        int nowPos = Horse[i];
        //다음 포지션 검색
        int nextPos = arr[nowPos][Move[idx]];

        //다음 포지션 중복 검색
        bool success = true;
        if (nextPos != 32) {
            for (int horse: Horse) {
                if (horse == nextPos)
                    success = false;
            }
        }

        if (!success)
            continue;

        Horse[i] = nextPos;
        go(idx + 1, score + arr[nextPos][0]);
        Horse[i] = nowPos;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 10; ++i)
        cin >> Move[i];

    go(0, 0);
    cout << Answer << '\n';
    return 0;
}