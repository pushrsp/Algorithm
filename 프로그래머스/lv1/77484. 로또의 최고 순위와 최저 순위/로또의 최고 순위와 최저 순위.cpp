#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    set<int> win;
    for (int &num: win_nums)
        win.insert(num);

    sort(lottos.begin(), lottos.end(), greater<>());

    int t = -1, match = 0;
    for (int i = 0; i < lottos.size(); ++i) {
        if (lottos[i] == 0) {
            t = i;
            break;
        }

        if (win.find(lottos[i]) != win.end()) {
            match += 1;
            win.erase(lottos[i]);
        }
    }

    int l = static_cast<int>(lottos.size()) - t;

    vector<int> answer;
    if (match < 2)
        answer.push_back(6);
    else
        answer.push_back(min(6, 7 - match));

    if (t != -1) {
        if (match + l < 2)
            answer.push_back(6);
        else
            answer.push_back(7 - (match + l));
    } else {
        answer.push_back(min(6, 7 - match));
    }

    sort(answer.begin(), answer.end());

    return answer;
}