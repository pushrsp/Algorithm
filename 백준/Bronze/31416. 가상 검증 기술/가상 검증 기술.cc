#include <cstring>
#include <vector>
#include <deque>
#include <iostream>
#include <cmath>
#include <map>

#define ll long long

using namespace std;

int Q, TA, TB, VA, VB;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> Q;
    while (Q--) {
        cin >> TA >> TB >> VA >> VB;

        int p1 = TB * VB, p2 = 0;
        while (VA > 0 && p2 < p1) {
            VA -= 1;
            p2 += TA;
        }

        for (int i = 0; i < VA; ++i) {
            if (p1 <= p2)
                p1 += TA;
            else
                p2 += TA;
        }

        cout << max(p1, p2) << '\n';
    }

    return 0;
}