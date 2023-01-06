#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <sstream>

#define ll long long
#define MONTH 12
#define DAY 28

using namespace std;

int Today;
unordered_map<string, int> Terms;

vector<string> split(string &s, char c) {
    stringstream ss(s);
    string segment;
    vector<string> ret;

    while (getline(ss, segment, c))
        ret.push_back(segment);

    return ret;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<string> s = split(today, '.');

    Today += stoi(s[2]);
    Today += stoi(s[1]) * DAY;
    Today += stoi(s[0]) * MONTH * DAY;

    for (string &term: terms) {
        s = split(term, ' ');
        Terms.insert(make_pair(s[0], stoi(s[1]) * DAY));
    }

    int due_date, start_date;
    string owner, privacy;
    vector<int> answer;

    for (int i = 0; i < privacies.size(); ++i) {
        privacy = privacies[i];

        s = split(privacy, ' ');
        owner = s[1];
        due_date = Terms.find(owner)->second;

        s = split(s[0], '.');
        start_date = stoi(s[2]);
        start_date += stoi(s[1]) * DAY;
        start_date += stoi(s[0]) * MONTH * DAY;

        if (start_date + due_date <= Today)
            answer.push_back(i + 1);
    }

    return answer;
}