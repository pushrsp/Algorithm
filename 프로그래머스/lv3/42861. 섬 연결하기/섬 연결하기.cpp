#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int> Parent;

bool cmp_vec(const vector<int> &a, const vector<int> &b) {
    return a[2] < b[2];
}

int get_parent(int x) {
    if (Parent[x] == x)
        return x;

    return Parent[x] = get_parent(Parent[x]);
}

void union_parent(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a < b)
        Parent[b] = a;
    else
        Parent[a] = b;
}

bool same_parent(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a == b)
        return true;

    return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    Parent = vector<int>(n, 1);
    sort(costs.begin(), costs.end(), cmp_vec);

    for (int i = 0; i < n; ++i)
        Parent[i] = i;

    int sum = 0;
    for (auto &cost: costs) {
        int n1 = cost[0], n2 = cost[1], dist = cost[2];

        if (!same_parent(n1, n2)) {
            union_parent(n1, n2);
            answer += dist;
        }
    }

    return answer;
}