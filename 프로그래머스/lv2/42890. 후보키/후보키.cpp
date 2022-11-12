#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int Answer = 0;
vector<vector<string>> DB;
vector<vector<int>> Candidates;
vector<int> Temp;

bool c1() {
    bool ret = true;
    set<string> cache;

    for (auto &db: DB) {
        string data = "";

        for (int &t: Temp)
            data += db[t] + ' ';

        if (!cache.empty() && cache.find(data) != cache.end()) {
            ret = false;
            break;
        }

        cache.insert(data);
    }

    return ret;
}

bool c2() {
    if (Temp.size() == 1)
        return true;

    for (vector<int> &candidate: Candidates) {
        bool ret = false;
        for (int &key: candidate) {
            if (find(Temp.begin(), Temp.end(), key) == Temp.end()) {
                ret = true;
                break;
            }
        }

        if (!ret)
            return ret;
    }

    return true;
}

void go(int count, int idx, int max_count) {
    if (count == max_count) {
        if (c1() && c2()) {
            Candidates.push_back(Temp);
            Answer++;
        }
        
        return;
    }

    for (int i = idx; i < DB[0].size(); ++i) {
        Temp.push_back(i);
        go(count + 1, i + 1, max_count);
        Temp.pop_back();
    }
}

int solution(vector<vector<string>> relation) {
    DB = relation;
    for (int i = 1; i <= DB[0].size(); ++i)
        go(0, 0, i);

    return Answer;
}