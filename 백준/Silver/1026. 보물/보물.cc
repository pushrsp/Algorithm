#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main() {
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);

    for (int n = 0; n < N; ++n)
        cin >> A[n];

    for (int n = 0; n < N; ++n)
        cin >> B[n];

    sort(A.begin(), A.end(), less<int>());
    sort(B.begin(), B.end(), greater<int>());

    int sum = 0;
    for (int n = 0; n < N; ++n)
        sum += A[n] * B[n];

    cout << sum << endl;
    return 0;
}