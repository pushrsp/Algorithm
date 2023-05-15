#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp_pair(const pair<int, int> &a, const pair<int, int> &b) {
    int d1 = a.second - a.first;
    int d2 = b.second - b.first;

    if (d1 == d2)
        return a.first < b.first;

    return d1 < d2;
}

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);

    set<string> s;

    for (auto &gem: gems)
        s.insert(gem);

    vector<pair<int, int>> candidates;
    candidates.emplace_back(1, static_cast<int>(gems.size()));

    set<string> t1;
    unordered_map<string, int> um;

    t1.insert(gems[0]);
    um.insert(make_pair(gems[0], 1));

    int left = 0, right = 0;
    while (right <= gems.size()) {
        if (left == right) {
            right++;
            continue;
        }

        if (t1.size() == s.size()) {
            candidates.emplace_back(left + 1, right);

            um[gems[left]]--;
            if (um[gems[left]] == 0) {
                um.erase(gems[left]);
                t1.erase(gems[left]);
            }

            left++;
        } else {
            if (right < gems.size()) {
                um[gems[right]]++;
                t1.insert(gems[right]);
            }

            right++;
        }
    }

    sort(candidates.begin(), candidates.end(), cmp_pair);
    
    answer[0] = candidates[0].first;
    answer[1] = candidates[0].second;

    return answer;
}