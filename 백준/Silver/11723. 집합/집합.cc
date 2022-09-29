#include <iostream>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int base = 0;

    while (N--) {
        string cmd;
        cin >> cmd;

        if (cmd == "empty") {
            base = 0;
            continue;
        }

        if (cmd == "all") {
            base = (1 << 21) - 1;
            continue;
        }

        int n;
        cin >> n;

        if (cmd == "add") {
            base |= (1 << n);
        } else if (cmd == "remove") {
            if (base & (1 << n))
                base &= ~(1 << n);
        } else if (cmd == "check") {
            if (base & (1 << n))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        } else {
            if (base & (1 << n))
                base &= ~(1 << n);
            else
                base |= (1 << n);
        }
    }
    return 0;
}