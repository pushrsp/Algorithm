#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 200001

using namespace std;

struct Ball {
    int w, c, i;
};

int N, Color[MAX], Weight[MAX], Answer[MAX];
vector<Ball> Balls;

bool cmp_ball(const Ball& a, const Ball& b) {
    if(a.w == b.w)
        return a.c < b.c;

    return a.w < b.w;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    cin >> N;
    Balls = vector<Ball>(N);
    for (int i = 0; i < N; ++i) {
        cin >> Balls[i].c >> Balls[i].w;

        Balls[i].i = i;
    }

    sort(Balls.begin(), Balls.end(), cmp_ball);

    int sum = 0;
    for (int n = 0; n < N; ++n) {
        int w = Balls[n].w, c = Balls[n].c, i = Balls[n].i;

        Color[c] += w;
        Weight[w] += w;
        sum += w;

        //크기와 색깔이 모두 같은 경우
        if(n != 0 && Balls[n - 1].c == c && Balls[n - 1].w == w) {
            Answer[i] = Answer[Balls[n - 1].i];
            continue;
        }

        Answer[i] = sum - Color[c] - Weight[w] + w;
    }

    for (int i = 0; i < N; ++i)
        cout << Answer[i] << '\n';

    return 0;
}