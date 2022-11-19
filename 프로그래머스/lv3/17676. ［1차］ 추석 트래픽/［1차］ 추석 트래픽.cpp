#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

vector<string> split(string &s, char c) {
    vector<string> ret;
    stringstream ss(s);
    string segment;

    while (getline(ss, segment, c))
        ret.push_back(segment);

    return ret;
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<int, int>> temp;

    for (auto &line: lines) {
        vector<string> request = split(line, ' ');
        vector<string> end = split(request[1], ':');
        vector<string> secs = split(end[2], '.');
        vector<string> d = split(request[2], 's');

        int eh = stoi(end[0]) * 3600 * 1000;
        int em = stoi(end[1]) * 60 * 1000;
        int es = stoi(secs[0]) * 1000 + stoi(secs[1]);
        int duration = static_cast<int>(stof(d[0]) * 1000);

        int e = eh + em + es;
        temp.emplace_back(e - duration + 1, e);
    }

    for (int i = 0; i < temp.size(); ++i) {
        int count = 0;
        for (int j = i; j < temp.size(); ++j) {
            if (temp[j].first < temp[i].second + 1000)
                count++;
        }

        answer = max(answer, count);
    }

    return answer;
}