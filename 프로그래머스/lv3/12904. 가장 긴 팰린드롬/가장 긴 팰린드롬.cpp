#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <cmath>

#define MAX 5000

using namespace std;

int IsPal(string &s, int left, int right) {
    while (0 <= left && right < s.length()) {
        if (s[left] != s[right])
            break;

        left--;
        right++;
    }

    return right - left - 1;
}

int solution(string s) {
    if (s.length() == 1)
        return 1;

    int answer = 0;
    for (int i = 1; i < s.length(); ++i)
        answer = max(answer, max(IsPal(s, i - 1, i + 1), IsPal(s, i - 1, i)));

    return answer;
}