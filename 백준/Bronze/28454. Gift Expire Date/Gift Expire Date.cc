#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

#define ll long long

using namespace std;

const int Day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int N;

vector<string> split(string &s, char c) {
    stringstream ss(s);
    string seg;
    vector<string> ret;

    while (getline(ss, seg, c))
        ret.push_back(seg);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;

    vector<string> sp = split(s, '-');

    int t_year = stoi(sp[0]);
    int t_month = stoi(sp[1]);
    int t_day = stoi(sp[2]);

    ll today = (t_year * 365) + t_day;
    for (int i = 1; i < t_month; ++i)
        today += Day[i];

    cin >> N;

    int ret = 0;
    for (int i = 0; i < N; ++i) {
        cin >> s;

        sp = split(s, '-');

        t_year = stoi(sp[0]);
        t_month = stoi(sp[1]);
        t_day = stoi(sp[2]);

        ll temp = (t_year * 365) + t_day;
        for (int j = 1; j < t_month; ++j)
            temp += Day[j];

        if (temp >= today)
            ret += 1;
    }

    cout << ret << '\n';

    return 0;
}