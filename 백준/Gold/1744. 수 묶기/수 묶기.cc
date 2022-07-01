#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, ZERO_CNT = 0, RESULT = 0;
vector<int> positive, negative;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;

        if (n > 1) {
            positive.push_back(n);
        } else if (n == 1) {
            RESULT += n;
        } else if (n == 0) {
            ZERO_CNT += 1;
        } else {
            negative.push_back(n);
        }
    }


    sort(positive.begin(), positive.end(), greater<int>());
    sort(negative.begin(), negative.end(), less<int>());

    for (int i = 0; i < positive.size() - (positive.size() % 2); i += 2) {
        RESULT += positive[i] * positive[i + 1];
    }

    if (positive.size() % 2 == 1)
        RESULT += positive.back();

    for (int i = 0; i < negative.size() - (negative.size() % 2); i += 2) {
        RESULT += negative[i] * negative[i + 1];
    }

    if (negative.size() % 2 == 1) {
        if (ZERO_CNT == 0)
            RESULT += negative.back();
    }

    cout << RESULT << endl;
    return 0;
}