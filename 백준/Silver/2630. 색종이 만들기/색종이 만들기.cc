#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> adj;
map<int, int> answer;

void Div(int _y, int _x, int size) {
    int cur = adj[_y][_x];

    for (int y = _y; y < _y + size; ++y) {
        for (int x = _x; x < _x + size; ++x) {
            if (cur != adj[y][x]) {
                Div(_y, _x, size / 2); //왼쪽 위
                Div(_y, _x + size / 2, size / 2);//오른쪽 위
                Div(_y + size / 2, _x, size / 2); //왼쪽 아래
                Div(_y + size / 2, _x + size / 2, size / 2); //오른쪽 아래
                return;
            }
        }
    }

    answer[cur]++;
}

int main() {
    int n;
    cin >> n;

    adj = vector<vector<int>>(n, vector<int>(n));
    answer[0] = 0;
    answer[1] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < adj[0].size(); ++j) {
            cin >> adj[i][j];
        }
    }

    Div(0, 0, n);

    cout << answer[0] << endl;
    cout << answer[1] << endl;

    return 0;
}