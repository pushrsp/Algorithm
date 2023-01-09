#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <cmath>
#include <algorithm>

#define ll long long

using namespace std;

string ToBin(ll n) {
    string s;

    while (n != 0) {
        if (n % 2 == 1)
            s.push_back('1');
        else
            s.push_back('0');

        n /= 2;
    }

    reverse(s.begin(), s.end());
    return s;
}

int GetHeight(int len) {
    int height = 0;
    while ((int) ::pow(2, height) - 1 < len)
        height += 1;

    return height;
}

string PadLeft(string &s, int len, int max_node) {
    string padding;
    for (int i = len; i < max_node; ++i)
        padding.push_back('0');

    return padding + s;
}

bool go(string s) {
    bool ret = true;

    int root = s.length() / 2;
    string left = s.substr(0, root);
    string right = s.substr(root + 1, s.length());

    if (s[root] == '0' && (left[left.length() / 2] == '1' || right[right.length() / 2] == '1'))
        return false;

    if (left.length() >= 3) {
        ret = go(left);
        if (ret)
            ret = go(right);
    }

    return ret;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for (auto &number: numbers) {
        string toBin = ToBin(number);

        int len = static_cast<int>(toBin.length());
        int height = GetHeight(len);
        int max_node = static_cast<int>(::pow(2, height)) - 1;

        toBin = PadLeft(toBin, len, max_node);
        if (go(toBin))
            answer.push_back(1);
        else
            answer.push_back(0);
    }

    return answer;
}