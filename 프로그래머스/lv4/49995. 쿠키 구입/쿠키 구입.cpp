#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <cmath>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;

    for (int i = 1; i < cookie.size(); ++i) {
        int l_idx = i - 1, r_idx = i;
        int l_sum = cookie[l_idx], r_sum = cookie[r_idx];

        while (0 <= l_idx && r_idx < cookie.size()) {
            if (l_sum == r_sum)
                answer = max(answer, l_sum);

            if (l_sum > r_sum) {
                r_idx++;
                r_sum += cookie[r_idx];
            } else {
                l_idx--;
                l_sum += cookie[l_idx];
            }
        }
    }

    return answer;
}