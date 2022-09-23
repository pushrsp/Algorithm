#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int Max_Alp = -1, Max_Cop = -1;
vector<vector<int>> Solved;
vector<vector<int>> Problems;
vector<vector<int>> Visited(1001, vector<int>(1001, INT32_MAX));

/*
 * 최단시간 bfs
 * { alp_req, cop_req, alp_rwd, cop_rwd, cost }
 * alp_req: 필요한 알고력
 * cop_req: 필요한 코딩력
 * alp_rew: 획득 알고력
 * cop_rew: 획득 코딩력
 * cost: 푸는 시간
 *
 * 문제 해결하기 위한 방법
 * 알고력 1을 높이기 위해 1시간 필요
 * 코딩력 1을 높이기 위해 1시간 필요
 * 혀냊 풀 수 있는 문제 중 하나, 여러번 풀기 가능
*/

struct Power {
    int alp, cop, time;
};

struct Cmp {
    bool operator()(const Power &a, const Power &b) {
        return a.time > b.time;
    }
};

int bfs(int startAlp, int startCop) {
    priority_queue<Power, vector<Power>, Cmp> pq;
    pq.push({startAlp, startCop, 0});

    while (!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        if (now.alp >= Max_Alp && now.cop >= Max_Cop)
            return now.time;

        if (now.time + 1 < Visited[now.alp + 1][now.cop]) {
            pq.push({now.alp + 1, now.cop, now.time + 1});
            Visited[now.alp + 1][now.cop] = now.time + 1;
        }

        if (now.time + 1 < Visited[now.alp][now.cop + 1]) {
            pq.push({now.alp, now.cop + 1, now.time + 1});
            Visited[now.alp][now.cop + 1] = now.time + 1;
        }

        for (auto &problem: Problems) {
            int alp_req = problem[0], cop_req = problem[1];
            int alp_rew = problem[2], cop_rew = problem[3];
            int cost = problem[4];

            if (now.alp >= alp_req && now.cop >= cop_req) {
                if (now.time + cost < Visited[now.alp + alp_rew][now.cop + cop_rew]) {
                    pq.push({now.alp + alp_rew, now.cop + cop_rew, now.time + cost});
                    Visited[now.alp + alp_rew][now.cop + cop_rew] = now.time + cost;
                }
            }
        }
    }

    return 0;
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    Problems = problems;

    for (auto &problem: Problems) {
        int alp_req = problem[0], cop_req = problem[1];
        Max_Alp = max(Max_Alp, alp_req);
        Max_Cop = max(Max_Cop, cop_req);
    }

    return bfs(alp, cop);
}