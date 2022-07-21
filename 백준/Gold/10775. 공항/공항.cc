#include <iostream>

using namespace std;

int G, P;
int GATE[100001] = {0};

int find(int g) {
    if (GATE[g] == g)
        return g;

    return GATE[g] = find(GATE[g]);
}

int main() {
    cin >> G >> P;

    for (int i = 1; i <= G; ++i)
        GATE[i] = i;

    int cnt = 0;
    for (int i = 0; i < P; ++i) {
        int g;
        cin >> g;

        int found = find(g);
        if (found == 0) {
            break;
        } else {
            cnt++;
            GATE[found] = find(found - 1);
        }
    }

    cout << cnt << endl;
    return 0;
}