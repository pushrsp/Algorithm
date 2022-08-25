#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, S;

int get_dist(vector<pair<int, int>> &vec) {
    int curNum = 0;
    int curPos = S;
    int answer = 0;
    vector<int> dist;

    while (!vec.empty()) {
        int pos = vec.back().first;
        int num = vec.back().second;

        if (num + curNum <= K) {
            vec.pop_back();
            curNum += num;
        } else {
            vec.back().second -= K - curNum;
            curNum += K - curNum;
        }

        answer += abs(curPos - pos);
        curPos = pos;

        if (curNum == K || vec.empty()) {
            answer += abs(curPos - S);
            curPos = S;
            curNum = 0;
        }
    }

    return answer;
}

int main() {
    cin >> N >> K >> S;

    vector<pair<int, int>> left, right;
    for (int n = 0; n < N; ++n) {
        int a, b;
        cin >> a >> b;

        if (a < S)
            left.emplace_back(a, b);
        else
            right.emplace_back(a, b);
    }

    sort(left.begin(), left.end(), greater<>());
    sort(right.begin(), right.end(), less<>());

    cout << get_dist(left) + get_dist(right) << endl;

    return 0;
}