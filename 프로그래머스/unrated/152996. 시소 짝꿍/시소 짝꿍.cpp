#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>

#define ll long long

using namespace std;
set<int> Weights;
unordered_map<int, ll> Count;

void Check(int weight, int div, ll dup, ll &answer) {
    if (weight % div == 0) {
        auto iter = Count.find(weight / div);
        if (iter != Count.end())
            answer += iter->second * dup;
    }
}

ll solution(vector<int> weights) {
    ll answer = 0;

    for (int &weight: weights) {
        Weights.insert(weight);
        Count[weight]++;
    }

    for (int weight: Weights) {
        ll dup = Count.find(weight)->second;

        int w2 = weight * 2;
        Check(w2, 3, dup, answer);
        Check(w2, 4, dup, answer);

        int w3 = weight * 3;
        Check(w3, 2, dup, answer);
        Check(w3, 4, dup, answer);

        int w4 = weight * 4;
        Check(w4, 2, dup, answer);
        Check(w4, 3, dup, answer);

        if (dup != 0)
            answer += (dup * (dup - 1)) / 2;

        Count.erase(weight);
    }

    return answer;
}