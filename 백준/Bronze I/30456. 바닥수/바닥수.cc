#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int N, L;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> L;

    for (int l = 0; l < L - 1; ++l)
        cout << 1;

    cout << N << '\n';
    
    return 0;
}