#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp_pair(const pair<int, int> &a, const pair<int, int> &b) {
    int len1 = a.second - a.first;
    int len2 = b.second - b.first;

    if (len1 == len2)
        return a.first < b.first;

    return len1 < len2;
}

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<pair<int, int>> candidates;

    int sum = sequence[0];
    int left = 0, right = 0;
    while (right < sequence.size()) {
        if (sum < k) {
            sum += sequence[++right];
        } else if (sum > k) {
            sum -= sequence[left++];
        } else {
            candidates.emplace_back(left, right);
            sum -= sequence[left];
            left++;
        }
    }

    sort(candidates.begin(), candidates.end(), cmp_pair);

    answer.push_back(candidates[0].first);
    answer.push_back(candidates[0].second);

    return answer;
}