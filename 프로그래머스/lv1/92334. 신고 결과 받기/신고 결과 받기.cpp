#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

vector<string> split(string &s, char c) {
    vector<string> ret;
    stringstream ss(s);
    string segment;

    while (getline(ss, segment, c))
        ret.push_back(segment);

    return ret;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    unordered_map<string, vector<string>> um;
    unordered_map<string, int> temp;
    set<string> st;

    for (auto &s: id_list) {
        um.insert(make_pair(s, vector<string>{}));
        temp.insert(make_pair(s, 0));
    }

    for (auto &r: report) {
        if (st.find(r) != st.end())
            continue;

        vector<string> s = split(r, ' ');
        um.find(s[1])->second.push_back(s[0]);
        st.insert(r);
    }

    for (const auto &p: um) {
        if (p.second.size() < k)
            continue;

        for (auto &s: p.second)
            temp[s]++;
    }

    for (auto &s: id_list)
        answer.push_back(temp[s]);

    return answer;
}