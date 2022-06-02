#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N;
vector<vector<int>> matrix;
map<int, int> answer;

bool isValid(int y, int x, int n) {
    int validNum = matrix[y][x];

    for (int i = y; i < y + n; ++i) {
        for (int j = x; j < x + n; ++j) {
            if (validNum != matrix[i][j])
                return false;
        }
    }

    return true;
}

void div(int y, int x, int n) {
    if (isValid(y, x, n)) {
        answer[matrix[y][x]]++;
    } else {
        int size = n / 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                div(y + size * i, x + size * j, size);
            }
        }
    }
}

int main() {
    cin >> N;

    matrix = vector<vector<int>>(N, vector<int>(N));

    answer[-1] = 0;
    answer[0] = 0;
    answer[1] = 0;

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> matrix[y][x];
        }
    }

    div(0, 0, N);

    cout << answer[-1] << endl;
    cout << answer[0] << endl;
    cout << answer[1] << endl;

    return 0;
}