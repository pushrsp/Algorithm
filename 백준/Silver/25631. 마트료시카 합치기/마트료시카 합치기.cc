#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

#define ll long long

using namespace std;

int N;
bool Visited[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    vector<int> vec(N);
    for (int n = 0; n < N; ++n)
        cin >> vec[n];

    sort(vec.begin(), vec.end());

    int ret = 0;
    for (int i = 0; i < N; ++i) {
        if (Visited[i])
            continue;

        Visited[i] = true;

        int prev = vec[i];
        for (int j = i + 1; j < N; ++j) {
            if (vec[j] > prev && !Visited[j]) {
                prev = vec[j];
                Visited[j] = true;
            }
        }

        ret += 1;
    }

    cout << ret << '\n';
    
    return 0;
}