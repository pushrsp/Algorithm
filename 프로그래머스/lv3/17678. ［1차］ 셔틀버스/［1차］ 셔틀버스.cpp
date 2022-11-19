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

const int MAX = (23 * 60) + 59;
vector<int> Vec;

vector<string> split(string &s, char c) {
    vector<string> ret;
    stringstream ss(s);
    string segment;

    while (getline(ss, segment, c))
        ret.push_back(segment);

    return ret;
}

pair<int, int> GetCrew(int m, int arrive_time) {
    pair<int, int> ret = {0, m};
    while (!Vec.empty() && Vec.back() <= arrive_time && ret.second > 0) {
        ret.first = max(ret.first, Vec.back());
        ret.second--;

        Vec.pop_back();
    }

    return ret;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    queue<int> q;
    q.push(9 * 60);

    for (auto &clock: timetable) {
        vector<string> r = split(clock, ':');
        int arrive_time = (stoi(r[0]) * 60) + stoi(r[1]);
        if (arrive_time == MAX)
            continue;

        Vec.push_back(arrive_time);
    }

    int temp = 0;
    sort(Vec.begin(), Vec.end(), greater<int>());
    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        pair<int, int> a = GetCrew(m, now);
        if (a.second > 0)
            temp = max(temp, now);
        else
            temp = max(temp, a.first - 1);

        n--;
        if (n > 0)
            q.push(now + t);
    }

    string hour = to_string(temp / 60);
    if (hour.length() == 1)
        answer += "0" + hour;
    else
        answer += hour;

    answer += ":";

    string min = to_string(temp % 60);
    if (min.length() == 1)
        answer += "0" + min;
    else
        answer += min;


    return answer;
}