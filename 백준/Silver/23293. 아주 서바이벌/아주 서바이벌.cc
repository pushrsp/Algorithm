#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>

#define ll long long

using namespace std;

struct Player {
    int location = 1;
    map<int, int> inventory;
};

int T, N;
bool B[100001];
Player P[100001];

bool has_item(int p_num, int item) {
    return P[p_num].inventory[item] > 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T >> N;

    vector<int> logs;

    int l_num, p_num, args1, args2;
    char cmd;
    for (int t = 0; t < T; ++t) {
        cin >> l_num >> p_num >> cmd;

        if (cmd == 'M') {
            cin >> args1;
            P[p_num].location = args1;
        } else if (cmd == 'F') {
            cin >> args1;
            P[p_num].inventory[args1] += 1;

            if (P[p_num].location != args1)
                logs.push_back(l_num);
        } else if (cmd == 'C') {
            cin >> args1 >> args2;

            if (!has_item(p_num, args1) || !has_item(p_num, args2))
                logs.push_back(l_num);

            P[p_num].inventory[args1] -= 1;
            P[p_num].inventory[args2] -= 1;

            if (P[p_num].inventory[args1] < 0)
                P[p_num].inventory[args1] = 0;
            if (P[p_num].inventory[args2] < 0)
                P[p_num].inventory[args2] = 0;

        } else {
            cin >> args1;

            if (P[p_num].location != P[args1].location) {
                logs.push_back(l_num);
                B[p_num] = true;
            }
        }
    }

    cout << logs.size() << '\n';

    if (!logs.empty()) {
        for (auto &l: logs)
            cout << l << ' ';
        cout << '\n';
    }

    vector<int> players;
    for (int n = 1; n <= N; ++n) {
        if (B[n])
            players.push_back(n);
    }

    cout << players.size() << '\n';

    if (!players.empty()) {
        for (auto &p: players)
            cout << p << ' ';
        cout << '\n';
    }

    return 0;
}