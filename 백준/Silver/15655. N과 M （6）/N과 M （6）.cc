#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;
int *arr2;
bool *visited;

void DFS(int depth, int next) {
    if (depth == M) {
        for (int i = 0; i < M; ++i) {
            cout << arr2[i] << ' ';
        }

        cout << '\n';
        return;
    }

    for (int i = next; i < N; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            arr2[depth] = arr[i];
            DFS(depth + 1, i + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;

    arr.reserve(N);
    visited = new bool[M];
    arr2 = new int[N];

    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;

        arr.push_back(n);
        arr2[i] = n;
    }

    sort(arr.begin(), arr.end());

    DFS(0, 0);
    return 0;
}