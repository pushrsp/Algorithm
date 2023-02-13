#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <sstream>

#define MAX 360001
#define HOUR 3600
#define MIN 60
#define ll long long

using namespace std;

int Arr[MAX];

vector<string> split(string &s, char c) {
    vector<string> ret;
    stringstream ss(s);
    string segment;

    while (getline(ss, segment, c))
        ret.push_back(segment);

    return ret;
}

string to_str(int time) { //정수형 시간을 문자열로 변환
    string ret = "";
    int h = time / 3600;
    time %= 3600;
    int m = time / 60;
    time %= 60;
    int s = time;
    if (h < 10) //1자리일 경우 0 추가
        ret += '0';
    ret += to_string(h);
    ret += ":";
    if (m < 10) //1자리일 경우 0 추가
        ret += '0';
    ret += to_string(m);
    ret += ":";
    if (s < 10) //1자리일 경우 0 추가
        ret += '0';
    ret += to_string(s);

    return ret;
}

int to_time(string &str) { //문자열 시간을 정수형으로 변환
    int h = stoi(str.substr(0, 2));
    int m = stoi(str.substr(3, 2));
    int s = stoi(str.substr(6, 2));
    int ret = s;
    ret += (m * 60);
    ret += (h * 3600);
    return ret;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int play_total = to_time(play_time);
    int adv_total = to_time(adv_time);

    for (auto &log: logs) {
        vector<string> log_duration = split(log, '-');
        int start_total = to_time(log_duration[0]);
        int end_total = to_time(log_duration[1]);

        for (int i = start_total; i < end_total; ++i)
            Arr[i] += 1;
    }

    ll sum = 0;
    for (int i = 1; i <= adv_total; ++i)
        sum += Arr[i];

    int temp = 0;
    ll max_sum = sum;
    for (int i = adv_total; i < play_total; ++i) {
        sum = sum - Arr[i - adv_total] + Arr[i];

        if (sum > max_sum) {
            temp = i - adv_total + 1;
            max_sum = sum;
        }
    }

    return to_str(temp);
}