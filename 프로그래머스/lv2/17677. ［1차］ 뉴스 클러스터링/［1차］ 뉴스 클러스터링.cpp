#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MUL = 65536;

void ToLower(string &s) {
    for (char &c: s) {
        if ('A' <= c && c <= 'Z')
            c += 32;
    }
}

bool RemoveIf(const string &s) {
    for (char c: s) {
        if (!('a' <= c && c <= 'z'))
            return true;
    }

    return false;
}

vector<string> MakeGroup(string &s) {
    vector<string> ret;
    for (int i = 0; i < s.size() - 1; i++) {
        string temp;
        temp += s[i];
        temp += s[i + 1];

        ret.push_back(temp);
    }

    return ret;
}

double GetGyo(unordered_map<string, int> a, unordered_map<string, int> b) {
    double ret = 0;
    for (const auto &iter: a) {
        int n1 = iter.second;
        auto t = b.find(iter.first);
        if (t == b.end())
            continue;

        ret += min(n1, t->second);
    }

    return ret;
}

double GetHap(unordered_map<string, int> &a, unordered_map<string, int> &b) {
    double ret = 0;

    for (const auto &iter: a) {
        if (b.find(iter.first) == b.end())
            ret += iter.second;
    }

    for (const auto &iter: b) {
        if (a.find(iter.first) == a.end())
            ret += iter.second;
    }

    for (const auto &iter: a) {
        int n1 = iter.second;
        auto t = b.find(iter.first);
        if (t == b.end())
            continue;

        ret += max(n1, t->second);
    }
    return ret;
}

int solution(string str1, string str2) {
    int answer = 0;

    ToLower(str1);
    ToLower(str2);

    vector<string> g1 = MakeGroup(str1);
    vector<string> g2 = MakeGroup(str2);

    g1.erase(remove_if(g1.begin(), g1.end(), RemoveIf), g1.end());
    g2.erase(remove_if(g2.begin(), g2.end(), RemoveIf), g2.end());

    if (g1.empty() && g2.empty())
        return MUL;

    unordered_map<string, int> um1;
    unordered_map<string, int> um2;

    for (auto &g: g1)
        um1[g]++;
    for (auto &g: g2)
        um2[g]++;

    double hap = GetHap(um1, um2);
    double gyo = GetGyo(um1, um2);

    answer = (gyo / hap) * MUL;

    return answer;
}