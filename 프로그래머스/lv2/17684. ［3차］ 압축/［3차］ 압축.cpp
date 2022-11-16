#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> m;


    for (int i = 0; i < 26; ++i) {
        string s;
        s.push_back(i + 'A');
        m.insert(make_pair(s, i + 1));
    }

    for (int i = 0; i < msg.length(); ++i) {
        int offset = 1, push = 1;
        while (i + offset <= msg.length() && m.find(msg.substr(i, offset)) != m.end()) {
            push = m.find(msg.substr(i, offset))->second;
            offset++;
        }

        answer.push_back(push);
        if (offset != 1 && i + offset <= msg.length())
            m.insert(make_pair(msg.substr(i, offset), m.size() + 1));

        i += offset - 2;
    }

    return answer;
}