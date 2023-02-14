#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MAX 100001

using namespace std;

int N, M, Arr[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> Arr[i];
        Arr[i] += Arr[i - 1];
    }

    int s, e;
    for (int i = 0; i < M; ++i) {
        cin >> s >> e;

        cout << Arr[e] - Arr[s - 1] << '\n';
    }
    return 0;
}