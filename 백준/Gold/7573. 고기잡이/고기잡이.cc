#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, I, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> I >> M;

//    vector<pair<int, int>> net;
//    for (int y = 1; y < I / 2; ++y)
//        net.emplace_back(y, (I / 2) - y);

    vector<pair<int, int>> point(M);
    for (int m = 0; m < M; ++m)
        cin >> point[m].first >> point[m].second;

    sort(point.begin(), point.end());

    int ret = 0;
    for (int h = 1; h < I / 2; ++h) {
        int w = I / 2 - h;
        if (w > N - 1 || h > N - 1)
            continue;

        for (int i = 0; i < M; ++i) {
            int y = point[i].first, x = point[i].second;
            for (int k = 0; k <= w; ++k) {
                int cnt = 1;
                for (int j = i + 1; j < M; ++j) {
                    int ny = point[j].first, nx = point[j].second;
                    if (ny > y + h)
                        break;

                    if (x - k <= nx && nx <= x - k + w)
                        cnt++;
                }

                ret = max(ret, cnt);
            }
        }
    }

    cout << ret << '\n';
    
    return 0;
}