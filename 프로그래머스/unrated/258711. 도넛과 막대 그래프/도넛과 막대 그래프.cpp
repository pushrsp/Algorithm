#include <string>
#include <vector>
#include <map>

using namespace std;

/*
 * first: get
 * second: give
*/

vector<int> solution(vector<vector<int>> edges) {    
    int len = 0;
    map<int, pair<int, int>> m;
    for(auto& e: edges) {
        int a = e[0], b = e[1];
        m[a].second++;
        m[b].first++;
        
        len = max(len, max(a, b));
    }
    
    vector<int> answer(4);
    for(int n = 1; n <= len; n++) {
        if(m[n].first == 0 && m[n].second >= 2)
            answer[0] = n;
    }
    
    for(int n = 1; n <= len; n++) {
        if(n == answer[0])
            continue;
        
        //8자 그래프
        if(m[n].first >= 2 && m[n].second >= 2) {
            answer[3] += 1;
            continue;
        }
        
        //막대 그래프
        if(m[n].second == 0) {
            answer[2] += 1;
            continue;
        }
    }
    
    //도넛 그래프
    answer[1] = m[answer[0]].second - answer[2] - answer[3];
    
    return answer;
}