#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <sstream>

using namespace std;

struct File {
    int index;
    string head;
    int number;
};

void ToLower(string &s) {
    for (char &c: s) {
        if ('A' <= c && c <= 'Z')
            c += 32;
    }
}

string GetHead(string &s) {
    string ret = "";
    for (char i: s) {
        if ('0' <= i && i <= '9')
            break;

        ret += i;
    }

    return ret;
}

string GetNums(string &s, int start) {
    string ret = "";
    for (int i = start; i < s.length(); ++i) {
        if ('0' <= s[i] && s[i] <= '9') {
            ret += s[i];
            continue;
        }

        break;
    }

    return ret;
}

string GetTail(string &s, int start) {
    string ret = "";
    for (int i = start; i < s.length(); ++i)
        ret += s[i];

    return ret;
}

bool cmp_file(const File &a, const File &b) {
    if (a.head == b.head) {
        if (a.number == b.number)
            return a.index < b.index;

        return a.number < b.number;
    }

    return a.head < b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;

    vector<File> temp;
    for (int i = 0; i < files.size(); ++i) {
        string s = files[i];
        ToLower(s);

        string head = GetHead(s);
        string nums = GetNums(s, head.size());
        string tail = GetTail(s, head.length() + nums.length());

        temp.push_back({i, head, stoi(nums)});
    }

    sort(temp.begin(), temp.end(), cmp_file);
    for (auto &file: temp)
        answer.push_back(files[file.index]);
    
    return answer;
}