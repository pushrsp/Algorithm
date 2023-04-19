#include <string>
#include <vector>
#include <cstring>
#include <queue>

#define INF 987654321
#define MAX 51

using namespace std;

vector<int> Picks;
int Answer = INT32_MAX;
int P[3][3] = {
    {1, 1, 1},
    {5, 1, 1},
    {25, 5, 1},
};

bool IsAllZero() {
    bool zero = true;
    for(int& p: Picks) {
        if(p != 0)
            zero = false;
    }
    
    return zero;
}

int Convert(string& mineral) {
    if(mineral == "diamond")
        return 0;
    else if(mineral == "iron")
        return 1;
    else
        return 2;
}

void go(queue<string> q, int p) {
    if(q.empty()) {
        Answer = min(Answer, p);
        return;
    }
    
    if(IsAllZero()) {
        Answer = min(Answer, p);
        return;
    }
    
    for(int i = 0; i < 3; i++) {
        if(Picks[i] == 0)
            continue;
        
        Picks[i] -= 1;
        
        queue<string> temp(q);
        int sum = p, count = 0;
        
        while(!temp.empty() && count < 5) {
            sum += P[i][Convert(temp.front())];
            temp.pop();
            count++;
        }
        
        go(temp, sum);
        
        Picks[i] += 1;
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    Picks = picks;
    
    queue<string> q;
    for(auto& mineral: minerals)
        q.push(mineral);
    
    go(q, 0);
    
    return Answer;
}