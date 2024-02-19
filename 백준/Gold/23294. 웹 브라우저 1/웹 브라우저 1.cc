#include <cstring>
#include <vector>
#include <deque>
#include <iostream>
#include <cmath>
#include <map>

#define ll long long

using namespace std;

int N, Q, C, CAP[2001], S[3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> Q >> C;

    for (int n = 1; n <= N; ++n)
        cin >> CAP[n];

    deque<int> f, c, b;

    char cmd;
    int i;
    for (int q = 0; q < Q; ++q) {
        cin >> cmd;

        if (cmd == 'B') {
            if (b.empty() || c.empty())
                continue;

            S[2] += CAP[c.front()];
            f.push_back(c.front());

            S[1] = 0;
            c.pop_front();

            S[1] = CAP[b.back()];
            c.push_back(b.back());

            S[0] -= CAP[b.back()];
            b.pop_back();
        } else if (cmd == 'F') {
            if (f.empty() || c.empty())
                continue;

            S[0] += CAP[c.front()];
            b.push_back(c.front());

            S[1] = 0;
            c.pop_front();

            S[1] = CAP[f.back()];
            c.push_back(f.back());

            S[2] -= CAP[f.back()];
            f.pop_back();
        } else if (cmd == 'A') {
            cin >> i;

            if (!c.empty()) {
                S[0] += CAP[c.front()];
                b.push_back(c.front());
                c.pop_front();
            }

            c.push_back(i);
            S[1] = CAP[i];

            f.clear();
            S[2] = 0;

            while (S[0] + S[1] + S[2] > C && !b.empty()) {
                S[0] -= CAP[b.front()];
                b.pop_front();
            }
        } else {
            if (b.empty())
                continue;
            
            deque<int> d;
            d.push_back(b.front());

            int cache = CAP[d.front()];
            for (int j = 1; j < b.size(); ++j) {
                if (d.back() != b[j]) {
                    d.push_back(b[j]);
                    cache += CAP[b[j]];
                }
            }

            S[0] = cache;

            b = d;
        }
    }


    cout << c.back() << '\n';

    if (b.empty()) {
        cout << -1 << '\n';
    } else {
        while (!b.empty()) {
            if (b.size() == 1)
                cout << b.back() << '\n';
            else
                cout << b.back() << ' ';

            b.pop_back();
        }
    }

    if (f.empty()) {
        cout << -1 << '\n';
    } else {
        while (!f.empty()) {
            if (f.size() == 1)
                cout << f.back() << '\n';
            else
                cout << f.back() << ' ';

            f.pop_back();
        }
    }

    return 0;
}