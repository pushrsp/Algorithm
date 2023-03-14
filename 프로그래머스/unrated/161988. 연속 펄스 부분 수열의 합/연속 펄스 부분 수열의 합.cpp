#include <string>
#include <vector>
#include <cmath>
#include <iostream>

#define ll long long
#define MAX 500001

using namespace std;

ll DP1[MAX], DP2[MAX];

ll Search(vector<int> &seq, ll dp[]) {
    int left = 0, right = 1;
    ll sum = 0, ret = 0;
    while (right <= seq.size()) {
        sum = dp[right] - dp[left];
        if (sum >= 0) {
            ret = max(ret, sum);
            right++;
        } else {
            left = right;
            right++;
        }
    }

    return ret;
}

ll solution(vector<int> sequence) {
    int op = 1;
    ll s1 = 0, s2 = 0;
    for (int i = 0; i < sequence.size(); ++i) {
        s1 += sequence[i] * op;
        DP1[i + 1] = s1;
        op *= -1;
        s2 += sequence[i] * op;
        DP2[i + 1] = s2;
    }

    ll answer = Search(sequence, DP1);
    answer = max(answer, Search(sequence, DP2));

    return answer;
}