#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define ll long long

using namespace std;

ll DP1[500001], DP2[500001];

ll solution(vector<int> sequence) {
    if (sequence.size() == 1) {
        return max((ll) sequence[0], (ll) sequence[0] * -1);
    }
    
    vector<int> t1, t2;;

    int offset = 1;
    for (int i = 0; i < sequence.size(); ++i) {
        t1.push_back(sequence[i] * offset);
        offset *= -1;
    }

    offset = -1;
    for (int i = 0; i < sequence.size(); ++i) {
        t2.push_back(sequence[i] * offset);
        offset *= -1;
    }

    DP1[0] = t1[0];
    DP2[0] = t2[0];

    ll answer = -50000000001;
    for (int i = 1; i < t1.size(); ++i) {
        DP1[i] = max(DP1[i - 1] + t1[i], (ll) t1[i]);
        answer = max(answer, DP1[i]);
    }

    for (int i = 1; i < t2.size(); ++i) {
        DP2[i] = max(DP2[i - 1] + t2[i], (ll) t2[i]);
        answer = max(answer, DP2[i]);
    }
    
    return answer;
}