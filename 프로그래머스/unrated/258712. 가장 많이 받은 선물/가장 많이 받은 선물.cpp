#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

int Stat[51][51];

vector<string> split(string& s, char c) {
    stringstream ss(s);
    string seg;
    vector<string> ret;
    
    while(getline(ss, seg, c))
        ret.push_back(seg);
    
    return ret;
}

int solution(vector<string> friends, vector<string> gifts) {
    map<string, int> strToIdx;
    for(int i = 0; i < friends.size(); i++)
        strToIdx.insert(make_pair(friends[i], i));
    
    for(auto& g: gifts) {
        vector<string> s = split(g, ' ');
        
        int from = strToIdx[s[0]], to = strToIdx[s[1]];
        Stat[from][to] += 1;
    }
    
    map<int, int> score;
    for(int i = 0; i < friends.size(); i++) {
        int give = 0;
        for(int j = 0; j < friends.size(); j++)
            give += Stat[i][j];
        
        int get = 0;
        for(int j = 0; j < friends.size(); j++)
            get += Stat[j][i];
        
        score.insert(make_pair(i, give - get));
    }
    
    
    int answer = 0;
    for(int i = 0; i < friends.size(); i++) {
        int gift = 0;
        for(int j = 0; j < friends.size(); j++) {
            if(i == j)
                continue;
            
            if(Stat[i][j] > Stat[j][i]) {
                gift += 1;
            } else if(Stat[i][j] < Stat[j][i]) {
                gift += 0;
            } else {
                int s1 = score[i], s2 = score[j];
                
                if(s1 > s2)
                    gift += 1;
            }
        }
        
        answer = max(answer, gift);
    }
    return answer;
}