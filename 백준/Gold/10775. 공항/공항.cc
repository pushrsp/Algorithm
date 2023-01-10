#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;

int G, P, Airplanes[MAX], Parent[MAX];

int GetParent(int i) {
    if (Parent[i] == i)
        return i;

    return Parent[i] = GetParent(Parent[i]);
}

void Union(int a, int b) {
    a = GetParent(a), b = GetParent(b);
    if (a != b)
        Parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> G;
    cin >> P;

    for (int i = 1; i <= P; ++i)
        cin >> Airplanes[i];

    for (int i = 1; i <= G; ++i)
        Parent[i] = i;

    int ret = 0;
    for (int i = 1; i <= P; ++i) {
        int parent = GetParent(Airplanes[i]);
        if (parent == 0)
            break;

        Union(parent, parent - 1);
        ret += 1;
    }

    cout << ret << '\n';
    return 0;
}