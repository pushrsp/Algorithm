#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int answer = 0, prev = 0;
    priority_queue<int> pq;

    for (int i = 0; i < A.size(); ++i) {
        for (int j = prev; j < B.size(); ++j) {
            pq.push(B[j]);
            prev += 1;

            if (B[j] > A[i])
                break;
        }

        if (!pq.empty() && pq.top() > A[i]) {
            answer += 1;
            pq.pop();
        }
    }
    
    return answer;
}