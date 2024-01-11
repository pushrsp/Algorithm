#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int N, A[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int num;
    for (int n = 0; n < N; ++n) {
        cin >> num;
        A[num] += 1;
    }

    int ret = 0;
    for (int n = 1; n <= 1000; ++n)
        ret += min(A[n], 2);

    cout << ret << '\n';
    
    return 0;
}