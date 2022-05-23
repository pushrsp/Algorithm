#include <iostream>

using namespace std;

string *arr;

void Find(int _y, int _x, int size) {
    char curr = arr[_y][_x];

    for (int i = _y; i < _y + size; i++) {
        for (int j = _x; j < _x + size; j++) {
            if (arr[i][j] != curr) {
                cout << '(';
                Find(_y, _x, size / 2);
                Find(_y, _x + size / 2, size / 2);
                Find(_y + size / 2, _x, size / 2);
                Find(_y + size / 2, _x + size / 2, size / 2);
                cout << ')';
                return;
            }
        }
    }


    cout << curr;
}

int main() {
    int n;
    cin >> n;

    arr = new string[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    Find(0, 0, n);

    return 0;
}