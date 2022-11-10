#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp_pair(pair<int, double> &a, pair<int, double> &b) {
    if (a.second == b.second)
        return a.first < b.first;

    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    double total = stages.size();
    unordered_map<int, pair<double, double>> um;

    for (int i = 1; i <= N; ++i) {
        double chal_count = 0;
        for (int &stage: stages) {
            if (stage == i)
                chal_count++;
        }

        if (chal_count > 0) {
            um[i].first = chal_count;
            um[i].second = total;
        } else {
            um[i].first = 0;
            um[i].second = 0;
        }

        total -= chal_count;
    }

    vector<pair<int, double>> temp;
    for (auto &iter: um) {
        if (iter.second.second == 0) {
            temp.emplace_back(iter.first, 0);
            continue;
        }

        double d = iter.second.first / iter.second.second;
        temp.emplace_back(iter.first, d);
    }

    sort(temp.begin(), temp.end(), cmp_pair);
    for (auto &t: temp)
        answer.push_back(t.first);

    return answer;
}