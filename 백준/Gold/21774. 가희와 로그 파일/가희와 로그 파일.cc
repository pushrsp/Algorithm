#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

#define ll long long

using namespace std;

const int Month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int N, Q;
vector<ll> Log[7];

vector<string> split(string &s, char c) {
    stringstream ss(s);
    vector<string> ret;
    string segment;

    while (getline(ss, segment, c))
        ret.push_back(segment);

    return ret;
}

ll get_sum(vector<string> &date, vector<string> &time) {
    ll ret = 0;

    int year = stoi(date[0]);
    int month = stoi(date[1]);
    int day = stoi(date[2]);
    int hour = stoi(time[0]);
    int min = stoi(time[1]);
    int sec = stoi(time[2]);

    ret += sec;
    ret += min * 60;
    ret += hour * 60 * 60;
    ret += (day - 1) * (3600 * 24); // day 시작은 1

    int to_day = 0;
    for (int i = 1; i < month; ++i) {
        if (i == 2 && year % 4 == 0)
            to_day += 29;
        else
            to_day += Month[i];
    }

    ret += to_day * (3600 * 24);

    to_day = 0;
    for (int i = 2000; i < year; ++i) {
        if (i % 4 == 0)
            to_day += 366;
        else
            to_day += 365;
    }

    ret += to_day * (3600 * 24);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> Q;
    cin.ignore();

    string s;
    for (int n = 0; n < N; ++n) {
        getline(cin, s);

        vector<string> ss = split(s, '#'); //날짜 시간, 레벨
        vector<string> d = split(ss[0], ' ');//날짜, 시간

        vector<string> date = split(d[0], '-');//년, 월, 일
        vector<string> time = split(d[1], ':');//시, 분, 초

        int level = stoi(ss[1]);
        ll sum = get_sum(date, time);

        for (int i = 1; i <= level; ++i)
            Log[i].push_back(sum);
    }

    for (int i = 1; i <= 6; ++i)
        sort(Log[i].begin(), Log[i].end());

    for (int q = 0; q < Q; ++q) {
        getline(cin, s);

        vector<string> ss = split(s, '#');

        int level = stoi(ss[2]);

        vector<string> start = split(ss[0], ' '); //날짜, 시간
        vector<string> start_date = split(start[0], '-'); //년, 월, 일
        vector<string> start_time = split(start[1], ':'); //시, 분, 초

        ll start_sum = get_sum(start_date, start_time);
        int i1 = lower_bound(Log[level].begin(), Log[level].end(), start_sum) - Log[level].begin();

        vector<string> end = split(ss[1], ' ');
        vector<string> end_date = split(end[0], '-'); //년, 월, 일
        vector<string> end_time = split(end[1], ':'); //시, 분, 초

        ll end_sum = get_sum(end_date, end_time);
        int i2 = upper_bound(Log[level].begin(), Log[level].end(), end_sum) - Log[level].begin();

        cout << i2 - i1 << '\n';
    }
    return 0;
}