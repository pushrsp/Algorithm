#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, S;

int get_dist(vector<pair<int, int>> &vec) {
    int answer = 0, seats = 0, apt = -1;

    while (!vec.empty()) {
        int pos = vec.back().first;
        int num = vec.back().second;

        int add = seats + num;
        if (add == K) {
            seats = 0;
            vec.pop_back();

            if (apt == -1) {
                answer += abs(S - pos) * 2;
            } else {
                answer += apt * 2;
                apt = -1;
            }

            continue;
        }

        if (add > K) {
            vec.back().second -= K - seats;
            seats = 0;
            answer += abs(S - pos) * 2;
        } else {
            seats += num;
            vec.pop_back();
            apt = max(apt, abs(S - pos));
        }

        if (vec.empty())
            answer += apt * 2;
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