#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

vector<double> Emoticons;
vector<vector<double>> Users;
double DC[4] = {10, 20, 30, 40};
vector<pair<int, int>> Temp;
vector<pair<int, double>> Answer;

void go(int n) {
    if (n == Emoticons.size()) {
        int count = 0;
        double sales = 0;

        for (auto &user: Users) {
            double max_dc = user[0], max_price = user[1], cur_price = 0;

            for (auto &emoticon: Temp) {
                if (emoticon.first >= max_dc)
                    cur_price += emoticon.second - (emoticon.second * (emoticon.first / (double) 100));
            }

            if (cur_price >= max_price)
                count += 1;
            else
                sales += cur_price;
        }

        Answer.emplace_back(count, sales);

        return;
    }

    for (double &i: DC) {
        Temp.emplace_back(i, Emoticons[n]);
        go(n + 1);
        Temp.pop_back();
    }
}

bool cmp_pair(const pair<int, double> &a, const pair<int, double> &b) {
    if (a.first == b.first)
        return a.second > b.second;

    return a.first > b.first;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    for (auto &emoticon: emoticons)
        Emoticons.push_back(emoticon);

    for (auto &user: users)
        Users.push_back({static_cast<double>(user[0]), static_cast<double>(user[1])});

    go(0);
    sort(Answer.begin(), Answer.end(), cmp_pair);
    
    vector<int> answer;
    answer.push_back(Answer[0].first);
    answer.push_back(static_cast<int>(Answer[0].second));
    return answer;
}