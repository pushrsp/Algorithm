#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <map>

#define INF 987654321

using namespace std;

vector<int> Adj[20001];
int Dist[20001];

void Di(int start) {
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, start);
    
    Dist[start] = 0;
    
    while(!pq.empty()) {
        int curr_node = pq.top().second;
        int curr_dist = -pq.top().first;
        pq.pop();
        
        for(int next_node: Adj[curr_node]) {
            int next_dist = curr_dist + 1;
            if(Dist[next_node] > next_dist) {
                Dist[next_node] = next_dist;
                pq.emplace(-next_dist, next_node);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    for(auto& e: edge) {
        Adj[e[0]].push_back(e[1]);
        Adj[e[1]].push_back(e[0]);
    }
    
    ::fill(Dist, Dist + 20001, INF);
    Di(1);
    
    map<int, int> m;
    int answer = 0;
    for(int i = 1; i <= n; i++) {
        if(Dist[i] == INF)
            continue;
        
        m[Dist[i]] += 1;
        answer = max(answer, Dist[i]);
    }
    
    return m[answer];
}