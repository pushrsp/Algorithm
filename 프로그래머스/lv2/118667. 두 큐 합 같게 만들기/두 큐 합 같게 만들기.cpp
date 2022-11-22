#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <deque>

#define MAX_SCORE 10

using namespace std;

#define ll long long

int solution(vector<int> queue1, vector<int> queue2) {
    deque<ll> dq1, dq2;

    ll sum = 0, n1 = 0, n2 = 0;
    for (int i = 0; i < queue1.size(); ++i) {
        n1 += queue1[i], n2 += queue2[i];
        sum += queue1[i] + queue2[i];

        dq1.push_back(queue1[i]), dq2.push_back(queue2[i]);
    }
    
    ll half = sum / 2;
    for (int i = 0; i < queue1.size(); ++i) {
        if (half < queue1[i] || half < queue2[i])
            return -1;
    }

    int answer = 0;
    while (n1 != n2 && !dq1.empty() && !dq2.empty()) {
        if(answer > sum + 2)
            return -1;
        
        while (n1 != n2 && n1 < n2 && !dq1.empty() && !dq2.empty()) {
            n1 += dq2.front(), n2 -= dq2.front();
            dq1.push_back(dq2.front());
            dq2.pop_front();
            answer++;
        }

        while (n1 != n2 && n2 < n1 && !dq1.empty() && !dq2.empty()) {
            n1 -= dq1.front(), n2 += dq1.front();
            dq2.push_back(dq1.front());
            dq1.pop_front();
            answer++;
        }
    }

    return answer;
}