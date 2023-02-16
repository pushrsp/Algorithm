#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <cmath>

#define MAX 27
#define INF 987654321

using namespace std;


int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    int Visited[MAX];
    for (auto &st: skill_trees) {
        fill(Visited, Visited + MAX, INF);

        for (int i = 0; i < skill.length(); ++i) {
            for (int j = 0; j < st.length(); ++j) {
                if (st[j] == skill[i])
                    Visited[skill[i] - 'A'] = j;
            }
        }

        int cmp = Visited[skill[0] - 'A'];
        int ret = 1;
        for (int i = 1; i < skill.length(); ++i) {
            if (cmp > Visited[skill[i] - 'A']) {
                ret = 0;
                break;
            }

            cmp = Visited[skill[i] - 'A'];
        }

        answer += ret;
    }

    return answer;
}