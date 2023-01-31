#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_map<string, int> um;
    set<string> s(gems.begin(), gems.end());

    int left = 0, right = 0;
    for (auto &gem: gems) {
        um[gem]++;
        if (um.size() == s.size())
            break;

        right++;
    }

    int min_len = right - left;
    answer.push_back(left + 1), answer.push_back(right + 1);

    while (right < gems.size()) {
        string key = gems[left];
        um[key]--, left++;

        if (um[key] == 0) {
            right++;
            for (; right < gems.size(); right++) {
                um[gems[right]]++;
                if (key == gems[right])
                    break;
            }

            if (right == gems.size())
                break;
        }

        if (right - left < min_len) {
            answer[0] = left + 1, answer[1] = right + 1;
            min_len = right - left;
        }
    }

    return answer;
}