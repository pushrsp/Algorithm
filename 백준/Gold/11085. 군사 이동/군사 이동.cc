#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1001

using namespace std;

struct Point {
    int n1, n2, cost;

    bool operator<(const Point &other) const {
        return cost > other.cost;
    }
};

int Parent[MAX];
vector<Point> Vec;

int GetParent(int i) {
    if (Parent[i] == i)
        return i;

    return Parent[i] = GetParent(Parent[i]);
}

void Union(int a, int b) {
    a = GetParent(a), b = GetParent(b);

    if (a < b)
        Parent[b] = a;
    else
        Parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int p, w;
    cin >> p >> w;

    int c, v;
    cin >> c >> v;


    Vec = vector<Point>(w);
    for (int i = 0; i < w; ++i)
        cin >> Vec[i].n1 >> Vec[i].n2 >> Vec[i].cost;

    for (int i = 0; i < MAX; ++i)
        Parent[i] = i;

    sort(Vec.begin(), Vec.end());

    for (auto &vec: Vec) {
        if (GetParent(vec.n1) != GetParent(vec.n2))
            Union(vec.n1, vec.n2);
        
        if (GetParent(c) == GetParent(v)) {
            cout << vec.cost << '\n';
            break;
        }
    }
    return 0;
}