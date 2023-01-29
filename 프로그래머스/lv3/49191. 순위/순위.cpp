#include <string>
#include <vector>
#include <iostream>
#include <set>

#define MAX 101

using namespace std;

set<int> Win[MAX], Lose[MAX];

int solution(int n, vector<vector<int>> results) {
    for (auto &result: results) {
        Win[result[1]].insert(result[0]);
        Lose[result[0]].insert(result[1]);
    }

    for (int i = 1; i <= n; ++i) {
        for (auto &w: Win[i]) { // i한테 이긴 선수들
            for (auto &l: Lose[i]) // i한테 진 선수들
                Lose[w].insert(l);
        }

        for (auto &l: Lose[i]) { // i한테 진 선수들
            for (auto &w: Win[i]) // i한테 이긴 선수들
                Win[l].insert(w);
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        if (Win[i].size() + Lose[i].size() == n - 1)
            answer += 1;
    }

    return answer;
}