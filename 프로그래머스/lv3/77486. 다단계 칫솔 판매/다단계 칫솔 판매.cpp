#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <sstream>

#define MAX 10001

using namespace std;

unordered_map<string, string> Tree;
unordered_map<string, int> StrToIdx;
int Amount[MAX];

void go(int amount, string referral) {
    if (referral == "-") {
        Amount[StrToIdx[referral]] += amount;
        return;
    }

    int a = amount / 10;
    if (a < 1) {
        Amount[StrToIdx[referral]] += amount;
        return;
    }

    Amount[StrToIdx[referral]] += amount - a;
    go(a, Tree[referral]);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    StrToIdx["-"] = 0;
    for (int i = 0; i < enroll.size(); ++i) {
        Tree[enroll[i]] = referral[i];
        StrToIdx[enroll[i]] = i + 1;
    }

    for (int i = 0; i < seller.size(); ++i) {
        go(amount[i] * 100, seller[i]);
    }

    vector<int> answer;
    for (int i = 1; i <= enroll.size(); ++i)
        answer.push_back(Amount[i]);
    
    return answer;
}