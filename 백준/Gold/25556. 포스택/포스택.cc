#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, A[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for (int n = 1; n <= N; ++n)
        cin >> A[n];

    vector<vector<int>> stacks(4);
    for (int i = 0; i < 4; ++i)
        stacks[i].push_back(0);

    for (int i = 1; i <= N; ++i) {
        bool find = false;

        for (int j = 0; j < 4; ++j) {
            if (stacks[j].back() < A[i]) {
                stacks[j].push_back(A[i]);
                find = true;
                break;
            }
        }

        if (!find) {
            cout << "NO" << '\n';
            return 0;
        }
    }

    cout << "YES" << '\n';
    
    return 0;
}