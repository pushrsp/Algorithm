#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

unordered_map<string, string> Tree;
unordered_map<string, int> Profit;

void go(string &name, int money) {
    if (name == "center")
        return;

    int p = static_cast<int>(money * 0.1);
    Profit.find(name)->second += (money - p);

    if (p < 1)
        return;

    go(Tree[name], p);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    for (int i = 0; i < enroll.size(); ++i) {
        Tree.insert(make_pair(enroll[i], referral[i] == "-" ? "center" : referral[i]));
        Profit.insert(make_pair(enroll[i], 0));
    }

    for (int i = 0; i < seller.size(); ++i)
        go(seller[i], amount[i] * 100);

    for (auto &e: enroll)
        answer.push_back(Profit.find(e)->second);

    return answer;
}