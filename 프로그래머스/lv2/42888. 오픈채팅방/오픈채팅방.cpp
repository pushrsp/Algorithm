#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    vector<pair<string, string>> temp;

    for (auto r: record) {
        int start = 0;
        vector<string> action;

        for (int i = 0; i < r.length(); i++) {
            if (r[i] == ' ') {
                action.push_back(r.substr(start, i - start));
                start = i + 1;
            }
        }

        if (action[0] != "Leave")
            m[action[1]] = r.substr(start);
        else
            action.push_back(r.substr(start));

        temp.push_back({action[0], action[1]});
    }

    for (auto t: temp) {
        string action = t.first;
        string id = t.second;

        if (action == "Enter")
            answer.push_back(m[id] + "님이 들어왔습니다.");
        else if (action == "Leave")
            answer.push_back(m[id] + "님이 나갔습니다.");
    }

    return answer;
}