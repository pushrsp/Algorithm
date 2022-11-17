#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

unordered_map<string, char> UM;

struct Music {
    int duration, index;
    string title;
};

bool cmp_music(const Music &a, const Music &b) {
    if (a.duration == b.duration)
        return a.index < b.index;

    return a.duration > b.duration;
}

vector<string> split(string &s, char c) {
    vector<string> ret;
    stringstream ss(s);
    string segment;

    while (getline(ss, segment, c))
        ret.push_back(segment);

    return ret;
}

string ReplaceSharp(string &s) {
    string ret;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i + 1] == '#') {
            ret += UM[s.substr(i, 2)];
            i += 1;
        } else {
            ret += s[i];
        }
    }

    return ret;
}

string solution(string m, vector<string> musicinfos) {
    //sharp
    {
        UM["C#"] = 'H';
        UM["D#"] = 'I';
        UM["F#"] = 'J';
        UM["G#"] = 'K';
        UM["A#"] = 'L';
    }

    {
        UM["C"] = 'C';
        UM["D"] = 'D';
        UM["E"] = 'E';
        UM["F"] = 'F';
        UM["G"] = 'G';
        UM["A"] = 'A';
        UM["B"] = 'B';
    }

    m = ReplaceSharp(m);

    vector<Music> temp;
    int index = 0;
    for (auto &info: musicinfos) {
        vector<string> v = split(info, ',');
        string title = v[2], len = ReplaceSharp(v[3]);

        vector<string> s = split(v[0], ':'), e = split(v[1], ':');
        int start = (stoi(s[0]) * 60) + stoi(s[1]), end = (stoi(e[0]) * 60) + stoi(e[1]);
        int duration = abs(end - start);

        string chord;
        for (int i = 0; i < duration; ++i)
            chord.push_back(len[i % len.length()]);

        for (int i = 0; i < chord.length(); ++i) {
            if (i + m.length() <= chord.length() && chord.substr(i, m.length()) == m) {
                temp.push_back({duration, index, title});
                break;
            }
        }

        index++;
    }

    if (temp.empty())
        return "(None)";

    sort(temp.begin(), temp.end(), cmp_music);
    return temp[0].title;
}