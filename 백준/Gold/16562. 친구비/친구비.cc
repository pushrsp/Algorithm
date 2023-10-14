#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define INF 987654321

using namespace std;

int N, M, K, Parent[10001], Fee[10001];
bool Visited[10001];

int get_parent(int i) {
    if (Parent[i] == i)
        return i;

    return Parent[i] = get_parent(Parent[i]);
}

void merge(int a, int b) {
    a = get_parent(a), b = get_parent(b);

    if (Fee[a] >= Fee[b])
        Parent[a] = b;
    else
        Parent[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> K;

    for (int n = 0; n <= N; ++n)
        Parent[n] = n;

    for (int n = 1; n <= N; ++n)
        cin >> Fee[n];

    int v, w;
    for (int m = 0; m < M; ++m) {
        cin >> v >> w;
        merge(v, w);
    }

    int ret = 0;
    for (int n = 1; n <= N; ++n) {
        int p = get_parent(n);
        if (!Visited[p]) {
            ret += Fee[p];
            Visited[p] = true;
        }
    }

    if (ret > K)
        cout << "Oh no" << '\n';
    else
        cout << ret << '\n';

    return 0;
}