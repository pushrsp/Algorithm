#include <iostream>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

int N, InOrder[100001], PostOrder[100001], I[100001];

void PreOrder(int in_left, int in_right, int po_left, int po_right) {
    if (in_left > in_right || po_left > po_right)
        return;

    int root = I[PostOrder[po_right]];
    int left = root - in_left, right = in_right - root;
    cout << InOrder[root] << ' ';

    PreOrder(in_left, root - 1, po_left, po_left + left - 1);
    PreOrder(root + 1, in_right, po_left + left, po_right - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int n = 1; n <= N; ++n) {
        cin >> InOrder[n];
        I[InOrder[n]] = n;
    }
    for (int n = 1; n <= N; ++n)
        cin >> PostOrder[n];

    PreOrder(1, N, 1, N);

    return 0;
}