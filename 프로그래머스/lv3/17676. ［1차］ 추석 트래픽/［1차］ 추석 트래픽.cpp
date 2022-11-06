#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> split(string &s, char c) {
    vector<string> ret;
    string segment;
    stringstream ss(s);

    while (getline(ss, segment, c))
        ret.push_back(segment);

    return ret;
}

/*
 * 응답완료시간(S): YYYY-MM-DD hh:mm:ss.sss
 * 처리시간(T): 0.1s 소수점 셋째 자리까지
*/

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<int, int>> vec;

    for (auto &line: lines) {
        vector<string> s1 = split(line, ' ');
        vector<string> s2 = split(s1[1], ':');
        vector<string> s3 = split(s1[2], 's');
        vector<string> s4 = split(s2[2], '.');

        int h = stoi(s2[0]);
        int m = stoi(s2[1]);
        int s = stoi(s4[0]) * 1000 + stoi(s4[1]);

        int p = static_cast<int>(stof(s3[0]) * 1000);

        int end = (h * 3600 * 1000) + (m * 60 * 1000) + s;
        int start = end - p + 1;
        vec.emplace_back(start, end);
    }

    for (int i = 0; i < lines.size(); ++i) {
        int end = vec[i].second;
        int count = 0;

        for (int j = i; j < lines.size(); ++j) {
            if (vec[j].first < end + 1000)
                count++;
        }

        answer = max(answer, count);
    }

    return answer;
}