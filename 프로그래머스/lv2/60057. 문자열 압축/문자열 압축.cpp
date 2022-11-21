#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

int solution(string s) {
    if (s.length() <= 3)
        return s.length();

    int answer = s.length();
    int mid = s.length() / 2;

    for (int i = 1; i <= mid; ++i) {
        int dup = 1;
        string temp, cmp;
        for (int j = 0; j < s.length(); j += i) {
            if (temp.empty()) {
                temp += s.substr(j, i);
                continue;
            }

            if (temp == s.substr(j, i)) {
                dup++;
                continue;
            }

            if (dup == 1)
                cmp += temp;
            else
                cmp += to_string(dup) + temp;

            dup = 1, temp = s.substr(j, i);
        }

        if (dup == 1)
            cmp += temp;
        else
            cmp += to_string(dup) + temp;

        answer = min(answer, static_cast<int>(cmp.length()));
    }

    return answer;
}