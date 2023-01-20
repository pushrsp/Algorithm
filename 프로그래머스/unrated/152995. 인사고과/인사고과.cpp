#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>

using namespace std;

struct S {
    int i, a, b;
};

bool Cmp1(const S &a, const S &b) {
    if (a.a == b.a)
        return a.b < b.b;

    return a.a > b.a;
}

bool Cmp2(const int &a, const int &b) {
    return a > b;
}

int solution(vector<vector<int>> scores) {
    vector<S> t1;
    vector<int> t2;

    for (int i = 0; i < scores.size(); ++i)
        t1.push_back({i, scores[i][0], scores[i][1]});

    sort(t1.begin(), t1.end(), Cmp1);

    int pivot = 0;
    for (int i = 0; i < t1.size(); ++i) {
        if (t1[i].b < pivot) {
            if (t1[i].i == 0)
                return -1;
        } else {
            t2.push_back(t1[i].a + t1[i].b);
            pivot = max(pivot, t1[i].b);
        }
    }

    t2.push_back(200001);
    sort(t2.begin(), t2.end(), Cmp2);

    int ret = -1, my_score = scores[0][0] + scores[0][1];
    for (int i = 0; i < t2.size(); ++i) {
        if (t2[i] == my_score) {
            ret = i;
            break;
        }
    }

    return ret;
}