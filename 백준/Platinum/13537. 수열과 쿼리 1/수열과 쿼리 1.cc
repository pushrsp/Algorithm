#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

#define MAX 100001

using namespace std;

int N, M, Arr[MAX], MST[18][MAX];

void go(int start, int end, int depth) {
    if (start == end) {
        MST[depth][start] = Arr[start];
    } else {
        int mid = (start + end) / 2;
        go(start, mid, depth + 1), go(mid + 1, end, depth + 1);
        int left = start, right = mid + 1, idx = start;

        while (left <= mid && right <= end) {
            if (MST[depth + 1][left] <= MST[depth + 1][right]) {
                MST[depth][idx] = MST[depth + 1][left++];
            } else {
                MST[depth][idx] = MST[depth + 1][right++];
            }

            idx += 1;
        }

        for (int i = left; i <= mid; ++i)
            MST[depth][idx++] = MST[depth + 1][i];
        for (int i = right; i <= end; ++i)
            MST[depth][idx++] = MST[depth + 1][i];
    }
}

int Query(int start, int end, int depth, int target, int i, int j) {
    if (start == i && end == j) {
        int left = start, right = end, mid;
        while (left <= right) {
            mid = (left + right) / 2;

            if (MST[depth][mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return end - right;
    }

    int mid = (start + end) / 2;
    if (mid < i)
        return Query(mid + 1, end, depth + 1, target, i, j);
    else if (mid >= j)
        return Query(start, mid, depth + 1, target, i, j);
    else
        return Query(start, mid, depth + 1, target, i, mid) + Query(mid + 1, end, depth + 1, target, mid + 1, j);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> Arr[i];

    go(1, N, 0);

    cin >> M;

    int i, j, k;
    for (int m = 0; m < M; ++m) {
        cin >> i >> j >> k;
        cout << Query(1, N, 0, k, i, j) << '\n';
    }
    return 0;
}