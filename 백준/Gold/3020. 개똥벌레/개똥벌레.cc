#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define MAX_HEIGHT 500001

using namespace std;

int N, H, Top[MAX_HEIGHT], Bottom[MAX_HEIGHT];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> H;

    int height;
    for (int i = 0; i < N; ++i) {
        cin >> height;

        if (i % 2)
            Bottom[height]++;
        else
            Top[H - height + 1]++;
    }

    for (int i = 1; i <= H; ++i) {
        Top[i] += Top[i - 1];
        Bottom[H - i] += Bottom[H - i + 1];
    }

    ll ret = 987654321;
    int count = 0;
    for (int i = 1; i <= H; ++i) {
        if (Top[i] + Bottom[i] < ret) {
            count = 1;
            ret = Top[i] + Bottom[i];
        } else if (Top[i] + Bottom[i] == ret) {
            count++;
        }
    }

    cout << ret << ' ' << count << '\n';

    return 0;
}