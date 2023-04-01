#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

struct Game {
    string a, b;
    double w{}, d{}, l{};
};

int Score[4];
map<string, int> TeamToIdx;
vector<Game> Games;
double Ret[4];

void go(int idx, double percentage) {
    if (idx == 6) {
        vector<pair<int, int>> vec(4);
        for (int i = 0; i < 4; ++i) {
            vec[i].first = Score[i];
            vec[i].second = i;
        }

        sort(vec.begin(), vec.end());

        int score0 = vec[0].first;
        int score1 = vec[1].first;
        int score2 = vec[2].first;
        int score3 = vec[3].first;

        int a = vec[0].second;
        int b = vec[1].second;
        int c = vec[2].second;
        int d = vec[3].second;

        if (score1 != score2) {
            Ret[c] += percentage;
            Ret[d] += percentage;
        } else if (score0 == score1 && score2 == score3) {
            Ret[a] += percentage / 2;
            Ret[b] += percentage / 2;
            Ret[c] += percentage / 2;
            Ret[d] += percentage / 2;
        } else if (score0 == score1) {
            Ret[a] += percentage / 3;
            Ret[b] += percentage / 3;
            Ret[c] += percentage / 3;
            Ret[d] += percentage;
        } else if (score2 == score3) {
            Ret[b] += percentage * 2 / 3;
            Ret[c] += percentage * 2 / 3;
            Ret[d] += percentage * 2 / 3;
        } else {
            Ret[b] += percentage / 2;
            Ret[c] += percentage / 2;
            Ret[d] += percentage;
        }
        return;
    }

    Game game = Games[idx];

    Score[TeamToIdx[game.a]] += 3;
    go(idx + 1, percentage * game.w);
    Score[TeamToIdx[game.a]] -= 3;

    Score[TeamToIdx[game.a]] += 1;
    Score[TeamToIdx[game.b]] += 1;
    go(idx + 1, percentage * game.d);
    Score[TeamToIdx[game.a]] -= 1;
    Score[TeamToIdx[game.b]] -= 1;

    Score[TeamToIdx[game.b]] += 3;
    go(idx + 1, percentage * game.l);
    Score[TeamToIdx[game.b]] -= 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    map<string, double> teams;

    string team;
    for (int i = 0; i < 4; ++i) {
        cin >> team;
        TeamToIdx[team] = i;
    }

    Games = vector<Game>(6);
    for (int i = 0; i < 6; ++i)
        cin >> Games[i].a >> Games[i].b >> Games[i].w >> Games[i].d >> Games[i].l;

    go(0, 1.0);

    cout << fixed;
    cout.precision(10);

    for (int i = 0; i < 4; ++i)
        cout << Ret[i] << '\n';

    return 0;
}