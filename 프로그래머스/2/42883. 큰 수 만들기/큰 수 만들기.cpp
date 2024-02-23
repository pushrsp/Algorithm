#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int s = 0;
    for(int i = 0; i < number.length() - k; i++) {
        char mx = number[s];
        int temp = s;
        for(int j = s; j <= k + i; j++) {
            if(number[j] > mx) {
                mx = number[j];
                temp = j;
            }
        }
        
        answer.push_back(mx);
        s = temp + 1;
    }
    
    return answer;
}