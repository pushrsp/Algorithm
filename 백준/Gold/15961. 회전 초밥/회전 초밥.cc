#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

#define ll long long
#define MAX 3000001

using namespace std;

int N, D, K, C, Arr[MAX + 3000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> D >> K >> C;
    for (int i = 1; i <= N; ++i)
        cin >> Arr[i];
    for (int i = 1; i <= K - 1; ++i)
        Arr[N + i] = Arr[i];

    unordered_map<int, int> um;
    um.insert(make_pair(C, 1));

    int left = 1, right = 1;
    int ret = 0;

    while (right < N + K) {
        auto iter = um.find(Arr[right]);
        if (iter == um.end())
            um.insert(make_pair(Arr[right], 1));
        else
            iter->second += 1;

        if (right - left == K - 1) {
            ret = max(ret, static_cast<int>(um.size()));
            iter = um.find(Arr[left]);
            if (iter->second - 1 == 0)
                um.erase(Arr[left]);
            else
                iter->second -= 1;

            left++;
        }

        right++;
    }

    cout << ret << '\n';

    return 0;
}