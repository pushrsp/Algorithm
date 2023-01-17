#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Team {
    int win, draw, lose;

    bool operator==(const Team &other) const {
        return win == other.win && draw == other.draw && lose == other.lose;
    }
};

Team Arr[6], Temp[6];
vector<pair<int, int>> Candidates;

int go(int n) {
    if (n == 15) {
        for (int i = 0; i < 6; ++i) {
            if (!(Arr[i] == Temp[i]))
                return 0;
        }

        return 1;
    }

    int ret = 0;
    int a = Candidates[n].first, b = Candidates[n].second;
    //w l
    Temp[a].win += 1, Temp[b].lose += 1;
    ret = max(ret, go(n + 1));
    Temp[a].win -= 1, Temp[b].lose -= 1;

    //l w
    Temp[a].lose += 1, Temp[b].win += 1;
    ret = max(ret, go(n + 1));
    Temp[a].lose -= 1, Temp[b].win -= 1;

    //d d
    Temp[a].draw += 1, Temp[b].draw += 1;
    ret = max(ret, go(n + 1));
    Temp[a].draw -= 1, Temp[b].draw -= 1;

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int i = 0; i < 6; ++i) {
        for (int j = i + 1; j < 6; ++j)
            Candidates.emplace_back(i, j);
    }

    for (int i = 0; i < 4; ++i) {
        for (Team &team: Arr)
            cin >> team.win >> team.draw >> team.lose;

        cout << go(0) << '\n';
    }

    return 0;
}