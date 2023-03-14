#include <string>
#include <vector>
#include <cmath>
#include <iostream>

#define ll long long
#define MAX 500001

using namespace std;

ll DP1[MAX], DP2[MAX];

ll solution(vector<int> sequence) {

    vector<ll> s1(sequence.size() + 1), s2(sequence.size() + 1);
    int op = 1;

    for (int i = 1; i <= sequence.size(); ++i) {
        s1[i] = sequence[i - 1] * op;
        op *= -1;
    }

    op = -1;
    for (int i = 1; i <= sequence.size(); ++i) {
        s2[i] = sequence[i - 1] * op;
        op *= -1;
    }

    DP1[1] = s1[1];
    DP2[1] = s2[1];

    ll answer = max(DP1[1], DP2[1]);
    for (int i = 2; i <= sequence.size(); ++i) {
        DP1[i] = max(s1[i], DP1[i - 1] + s1[i]);
        DP2[i] = max(s2[i], DP2[i - 1] + s2[i]);

        answer = max(answer, max(DP1[i], DP2[i]));
    }

    return answer;
}