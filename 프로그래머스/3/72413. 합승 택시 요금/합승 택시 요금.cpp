#include <string>
#include <vector>

#define INF 30000000

using namespace std;

int Dist[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j)
                Dist[i][j] = 0;
            else
                Dist[i][j] = INF;
        }
    }
    
    for(auto& fare: fares) {
        Dist[fare[0]][fare[1]] = fare[2];
        Dist[fare[1]][fare[0]] = fare[2];
    }
    
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(Dist[i][j] > Dist[i][k] + Dist[k][j])
                    Dist[i][j] = Dist[i][k] + Dist[k][j];
            }
        }
    }
    
    int answer = INT32_MAX;
    for(int i = 1; i <= n; i++)
        answer = min(answer, Dist[s][i] + Dist[i][a] + Dist[i][b]);
    
    
    return answer;
}