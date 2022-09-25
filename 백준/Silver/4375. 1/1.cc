#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (scanf("%d\n", &n) != EOF) {
        int cnt = 1, ret = 1;

        while (true) {
            if (cnt % n == 0) {
                cout << ret << "\n";
                break;
            } else {
                cnt = (cnt * 10) + 1;
                cnt %= n;
                ret++;
            }
        }
    }
    return 0;
}