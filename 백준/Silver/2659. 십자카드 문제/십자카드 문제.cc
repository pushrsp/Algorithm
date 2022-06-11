#include <iostream>
#include <algorithm>

using namespace std;

bool visited[10000] = {false,};

int get_min(int i, int j, int k, int l) {
    int a = i * 1000 + j * 100 + k * 10 + l;
    int b = j * 1000 + k * 100 + l * 10 + i;
    int c = k * 1000 + l * 100 + i * 10 + j;
    int d = l * 1000 + i * 100 + j * 10 + k;

    return min({a, b, c, d});
}

void all_num() {
    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j < 10; ++j) {
            for (int k = 1; k < 10; ++k) {
                for (int l = 1; l < 10; ++l) {
                    int num = get_min(i, j, k, l);
                    if (!visited[num])
                        visited[num] = true;
                }
            }
        }
    }
}

int main() {
    int i, j, k, l;
    cin >> i >> j >> k >> l;
    int min = get_min(i, j, k, l);

    all_num();

    int cnt = 0;
    for (int m = 1111; m <= min; ++m) {
        if (visited[m])
            cnt++;
    }

    cout << cnt << endl;
    return 0;
}