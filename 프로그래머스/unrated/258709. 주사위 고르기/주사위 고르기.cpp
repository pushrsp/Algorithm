#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> Candidate;
vector<int> Temp;

void go(int n, int idx, vector<vector<int>>& dice) {
    if(n == N / 2) {
        Candidate.push_back(Temp);
        return;
    }
    
    for(int i = idx; i < N; i++) {
        Temp.push_back(i);
        go(n + 1, i + 1, dice);
        Temp.pop_back();
    }
}

void go2(int n, int sum, vector<int>& team, vector<int>& ret, vector<vector<int>>& dice) {
    if(n == team.size()) {
        ret.push_back(sum);
        return;
    }
    
    for(int i = 0; i < 6; i++)
        go2(n + 1, sum + dice[team[n]][i], team, ret, dice);
}

vector<int> solution(vector<vector<int>> dice) {
    N = static_cast<int>(dice.size());
    vector<int> answer(N / 2);
    
    go(0, 0, dice);
    
    int ret = 0;
    for(int i = 0; i < Candidate.size(); i++) {
        vector<bool> visited(N);
        for(int j = 0;j < Candidate[i].size(); j++)
            visited[Candidate[i][j]] = true;
        
        vector<int> a, b;
        for(int j = 0; j < N; j++) {
            if(visited[j])
                a.push_back(j);
            else
                b.push_back(j);
        }
        
        vector<int> s1, s2;
        go2(0, 0, a, s1, dice);
        go2(0, 0, b, s2, dice);
        
        sort(s2.begin(), s2.end());
        
        int w = 0;
        for(auto& s: s1) {
            int idx = lower_bound(s2.begin(), s2.end(), s) - s2.begin();
            while(idx > 0 && s2[idx] >= s)
                idx--;
            
            if(s2[idx] == s)
                continue;
            
            w += min((int) s2.size(), idx + 1);
        }
        
        if(w > ret) {
            ret = w;
            
            for(int i = 0; i < a.size(); i++)
                answer[i] = a[i] + 1;
        }
    }
    
    return answer;
}