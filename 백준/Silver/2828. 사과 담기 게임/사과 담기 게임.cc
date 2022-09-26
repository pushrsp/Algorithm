#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N, M, J;

int main() {
    cin >> N >> M >> J;

    int left = 1;
    int move = 0;
    for (int i = 0; i < J; ++i) {
        int right = left + M - 1;
        int apple;
        cin >> apple;

        if (left <= apple && apple <= right) {
            continue;
        } else {
            if (right < apple) {
                move += apple - right;
                left = apple - M + 1;
            } else {
                move += abs(apple - left);
                left = apple;
            }
        }
    }

    cout << move << endl;
    return 0;
}