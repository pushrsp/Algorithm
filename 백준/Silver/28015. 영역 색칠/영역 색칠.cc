#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

#define ll long long

using namespace std;

int N, M, A[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x)
            cin >> A[y][x];
    }

    int ret = 0;
    for (int y = 0; y < N; ++y) {
        vector<int> temp;

        for (int x = 0; x < M; ++x) {
            if (A[y][x] == 0) {
                if (temp.empty())
                    continue;

                int one = 0, two = 0;
                for (int i = 0; i < temp.size(); ++i) {
                    int j = i + 1;
                    for (; j < temp.size(); j++) {
                        if (temp[i] != temp[j])
                            break;
                    }

                    i = j - 1;

                    if (temp[i] == 1)
                        one += 1;
                    else
                        two += 1;
                }

                temp.clear();

                ret += min(one, two) + 1;
            } else {
                temp.push_back(A[y][x]);
            }
        }

        if (temp.empty())
            continue;

        int one = 0, two = 0;
        for (int i = 0; i < temp.size(); ++i) {
            int j = i + 1;
            for (; j < temp.size(); j++) {
                if (temp[i] != temp[j])
                    break;
            }

            i = j - 1;

            if (temp[i] == 1)
                one += 1;
            else
                two += 1;
        }

        ret += min(one, two) + 1;
    }

    cout << ret << '\n';

    return 0;
}