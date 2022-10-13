#include <string>
#include <vector>

using namespace std;

bool Dp[10];

int solution(vector<int> numbers) {
    int answer = 0;
    
    for(int& num: numbers)
        Dp[num] = true;
    
    for(int i = 0; i < 10; i++) {
        if(!Dp[i])
            answer += i;
    }
    
    return answer;
}