#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;

    rocks.push_back(0);
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);

    int left = rocks.front(), right = rocks.back(), mid;
    while (left <= right) {
        mid = (left + right) / 2;

        int remove = 0;
        int start = rocks[0];

        for (int i = 1; i < rocks.size(); ++i) {
            if (rocks[i] - start < mid)
                remove++;
            else
                start = rocks[i];
        }

        if (remove <= n) {
            left = mid + 1;
            answer = max(answer, mid);
        } else {
            right = mid - 1;
        }
    }

    return answer;
}