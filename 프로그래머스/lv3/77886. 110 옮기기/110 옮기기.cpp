#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;

    for (auto &x: s) {
        string prev;
        int count = 0;

        for (int i = 0; i < x.length(); ++i) {
            prev += x[i];

            if (prev.length() >= 3 && prev.substr(prev.length() - 3) == "110") {
                count++;
                prev.erase(prev.length() - 3, 3);
            }
        }

        if (count == 0) {
            answer.push_back(x);
            continue;
        }

        int i;
        for (i = prev.length() - 1; i >= 0; i--) {
            if (prev[i] == '0')
                break;
        }

        for (int j = 0; j < count; ++j)
            prev.insert(i + 1, "110");

        answer.push_back(prev);
    }

    return answer;
}