#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_idx(vector<int> &reserve, int i) {
    for (int r = 0; r < reserve.size(); r++) {
        if (reserve[r] - 1 == i || reserve[r] + 1 == i) {
            reserve.erase(reserve.begin() + r);
            return r;
        }
    }

    return -1;
}

int solution(int n, vector<int> lost, vector<int> reserve) {

    for (int i = 0; i < lost.size(); ++i) {
        for (int j = 0; j < reserve.size(); ++j) {
            if (lost[i] == reserve[j]) {
                reserve.erase(reserve.begin() + j);
                lost.erase(lost.begin() + i);
                i = -1;
                break;
            }
        }
    }

    int answer = n - lost.size();

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (int i: lost) {
        if (get_idx(reserve, i) != -1)
            answer++;
    }

    cout << answer << endl;
    return answer;
}