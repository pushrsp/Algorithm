#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Ret = INT32_MAX;
vector<string> Minerals;
vector<int> Picks;
int Pi[3][3] = {
    {1, 1, 1},
    {5, 1, 1},
    {25, 5, 1},
};

int GetIndex(string& mineral) {
    if(mineral == "diamond")
        return 0;
    else if(mineral == "iron")
        return 1;
    else
        return 2;
}

void go(int pick_index, int mineral_index, int sum, int count) {
    if(mineral_index == Minerals.size()) {
        Ret = min(Ret, count);
        return;
    }
    
    if(count % 5 == 0)
        pick_index += 1;
    if(Picks[pick_index] == 0)
        pick_index += 1;
    
    go(pick_index, mineral_index + 1, sum + Pi[pick_index][GetIndex(Minerals[mineral_index])], count + 1);
}

int solution(vector<int> picks, vector<string> minerals) {
    Picks = picks;
    Minerals = minerals;
    go(0, 0, 0, 0);
    cout << Ret << '\n';
    int answer = 0;
    return answer;
}