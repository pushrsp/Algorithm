#include <iostream>
#include <algorithm>
#include <set>

#define MAX 1000001

using namespace std;

int Z, N, M;
int Weather[MAX], Prev[MAX], Answer[MAX];

bool Search() {
    fill(Answer, Answer + MAX, 0);
    fill(Prev, Prev + MAX, 0);
    set<int> s;

    for (int i = 0; i < M; ++i) {
        if (Weather[i]) {
            auto it = s.lower_bound(Prev[Weather[i]]);
            if (it == s.end())
                return false;

            int index = *it;
            Answer[index] = Weather[i];
            Prev[Weather[i]] = i;
            s.erase(it);
        } else {
            s.insert(i);
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> Z;
    while (Z--) {
        cin >> N >> M;

        for (int i = 0; i < M; ++i)
            cin >> Weather[i];

        if (Search()) {
            cout << "YES" << '\n';
            for (int i = 0; i < M; ++i) {
                if (!Weather[i])
                    cout << Answer[i] << ' ';
            }
            cout << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}