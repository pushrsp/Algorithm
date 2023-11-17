#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b) {
    if(a[0] == b[0])
        return a[1] > b[1];
    
    return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), cmp);
    
    int prev = routes[0][1];
    int answer = 1;
    for(auto& r: routes) {
        if(prev < r[0]) {
            answer += 1;
            prev = r[1];
        }
        
        if(prev >= r[1])
            prev = r[1];
    }
    
    return answer;
}