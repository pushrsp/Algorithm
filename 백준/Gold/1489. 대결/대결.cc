#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A, B;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    A = vector<int>(N);
    B = vector<int>(N);

    for (int n = 0; n < N; ++n)
        cin >> A[n];
    for (int n = 0; n < N; ++n)
        cin >> B[n];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ret = 0;
    for (int n = 0; n < N; ++n) {
        if (A[n] > B[n])
            ret += 2;
        else if (A[n] == B[n])
            ret += 1;
    }

    vector<int> prev(A.begin(), A.end());
    for (int i = 1; i < N; ++i) {
        vector<int> temp(N);
        for (int n = 0; n < N; ++n)
            temp[n] = prev[(n + 1) % N];

        int score = 0;
        for (int n = 0; n < N; ++n) {
            if (temp[n] > B[n])
                score += 2;
            else if (temp[n] == B[n])
                score += 1;
        }

        ret = max(ret, score);
        prev = vector<int>(temp.begin(), temp.end());
    }

    cout << ret << '\n';

    return 0;
}