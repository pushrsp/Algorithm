#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> m;

bool cmp(pair<string, int> &a, pair<string, int> &b) {
    return a.second > b.second;
}

void comb(string order, int size, string s, int idx) {
    if (s.length() == size) {
        map<string, int>::iterator iter;
        iter = m.find(s);
        
        if (iter != m.end())
            iter->second++;
        else
            m.insert(pair<string, int>(s, 1));

        return;
    }

    for (int i = idx; i < order.length(); i++)
        comb(order, size, s + order[i], i + 1);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int i: course) {
        m.clear();

        for (auto &order: orders) {
            sort(order.begin(), order.end());
            if (i <= order.length())
                comb(order, i, "", 0);
        }

        vector<pair<string, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), cmp);

        if (!v.empty()) {
            int biggest = v[0].second;

            if (biggest >= 2) {
                for (auto &p: v) {
                    if (p.second == biggest) {
                        answer.push_back(p.first);
                    } else {
                        break;
                    }
                }
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}