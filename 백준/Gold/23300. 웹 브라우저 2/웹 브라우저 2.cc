#include <cstring>
#include <vector>
#include <deque>
#include <iostream>
#include <cmath>
#include <map>

#define ll long long

using namespace std;

int N, Q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> Q;

    deque<int> f, c, b;

    char cmd;
    int i;
    for (int q = 0; q < Q; ++q) {
        cin >> cmd;

        if (cmd == 'B') {
            if (b.empty())
                continue;

            f.push_back(c.front());
            c.pop_front();

            c.push_back(b.back());
            b.pop_back();
        } else if (cmd == 'F') {
            if (f.empty())
                continue;

            b.push_back(c.front());
            c.pop_front();

            c.push_back(f.back());
            f.pop_back();
        } else if (cmd == 'A') {
            cin >> i;

            if (!c.empty()) {
                b.push_back(c.front());
                c.pop_front();
            }

            c.push_back(i);
            f.clear();
        } else {
            if (b.empty())
                continue;

            deque<int> d;
            d.push_back(b.front());

            for (int j = 1; j < b.size(); ++j) {
                if (d.back() != b[j])
                    d.push_back(b[j]);
            }

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