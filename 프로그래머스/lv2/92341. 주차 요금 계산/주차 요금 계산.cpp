#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <cmath>

#define ll long long

using namespace std;

vector<string> split(string &s, char c) {
    vector<string> ret;
    stringstream ss(s);
    string segment;

    while (getline(ss, segment, c))
        ret.push_back(segment);

    return ret;
}

bool cmp_pair(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    int max_time = 23 * 60 + 59;
    unordered_map<string, stack<int>> um1;
    unordered_map<string, int> um2;

    int f_min = fees[0], f_won = fees[1], f_dur = fees[2], f_dur_won = fees[3];
    for (auto &s: records) {
        vector<string> ss = split(s, ' ');
        vector<string> time = split(ss[0], ':');

        int t = stoi(time[0]) * 60 + stoi(time[1]);

        auto iter = um1.find(ss[1]);
        if (iter == um1.end()) {
            um1.insert(make_pair(ss[1], stack<int>{}));
            iter = um1.find(ss[1]);
        }

        if (ss[2] == "IN") {
            iter->second.push(t);
        } else {
            int dur = t - iter->second.top();
            iter->second.pop();

            um2[ss[1]] += dur;
        }
    }

    for (auto &p: um1) {
        if (p.second.empty())
            continue;

        int dur = max_time - p.second.top();
        um2[p.first] += dur;
        p.second.pop();
    }

    vector<pair<int, int>> temp;
    for (auto &p: um2) {
        if (p.second <= f_min) {
            temp.emplace_back(stoi(p.first), f_won);
            continue;
        }

        int fee = f_won, duration = p.second - f_min, extra;

        duration /= f_dur;
        if ((p.second - f_min) % f_dur)
            duration += 1;

        extra = duration * f_dur_won;
        temp.emplace_back(stoi(p.first), fee + extra);
    }

    sort(temp.begin(), temp.end(), cmp_pair);
    for (auto &p: temp)
        answer.push_back(p.second);

    return answer;
}