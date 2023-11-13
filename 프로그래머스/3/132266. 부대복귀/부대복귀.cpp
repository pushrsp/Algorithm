#include <string>
#include <vector>
#include <queue>
#include <cstring>

#define INF 987654321

using namespace std;

vector<int> Adj[100001];
int Dist[100001];

void Di(int start) {
    priority_queue<pair<int, int>> pq;
    
    pq.push({0, start});
    Dist[start] = 0;
    
    while(!pq.empty()) {
        int curr_node = pq.top().second;
        int curr_dist = -pq.top().first;
        pq.pop();
        
        for(auto& next: Adj[curr_node]) {
            int next_dist = curr_dist + 1;
            if(Dist[next] > next_dist) {
                Dist[next] = next_dist;
                pq.push({-next_dist, next});
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    for(auto& road: roads) {
        Adj[road[0]].push_back(road[1]);
        Adj[road[1]].push_back(road[0]);
    }
    
    fill(Dist, Dist + 100001, INF);
    Di(destination);
    
    vector<int> answer;
    for(auto& source: sources) {
        if(Dist[source] == INF)
            answer.push_back(-1);
        else
            answer.push_back(Dist[source]);
    }
    
    return answer;
}