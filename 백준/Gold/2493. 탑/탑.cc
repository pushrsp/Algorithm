#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, Arr[500001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for (int n = 1; n <= N; ++n)
        cin >> Arr[n];

    stack<pair<int, int>> st;
    for (int n = 1; n <= N; ++n) {
        while (!st.empty() && st.top().second < Arr[n])
            st.pop();

        if (st.empty())
            cout << 0 << ' ';
        else
            cout << st.top().first << ' ';

        st.emplace(n, Arr[n]);
    }

    return 0;
}