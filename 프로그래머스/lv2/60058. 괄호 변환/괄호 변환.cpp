#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

bool IsValid(string &s) {
    stack<char> st;

    for (char &c: s) {
        if (c == '(') {
            st.push(c);
        } else {
            if (st.empty())
                return false;

            st.pop();
        }
    }

    return st.empty();
}

string go(string p) {
    if (p.empty())
        return "";

    string u, v;
    int left = 0, right = 0;

    for (int i = 0; i < p.length(); ++i) {
        if (p[i] == '(')
            left++;
        else
            right++;

        if (left == right) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }

    if (IsValid(u))
        return u + go(v);

    string temp = "(" + go(v) + ")";
    u = u.substr(1, u.length() - 2);

    for (char i: u) {
        if (i == '(')
            temp += ')';
        else
            temp += '(';
    }

    return temp;
}

string solution(string p) {
    if (IsValid(p))
        return p;

    return go(p);
}