#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

#define ll long long

using namespace std;

ll N, Arr[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (true) {
        cin >> N;
        if (N == 0)
            break;

        for (int i = 0; i < N; ++i)
            cin >> Arr[i];

        Arr[N] = -1;

        ll answer = 0;
        stack<int> st;
        for (int i = 0; i <= N; ++i) {
            while (!st.empty() && Arr[i] < Arr[st.top()]) {
                ll h, w;

                h = st.top();
                st.pop();

                if (st.empty())
                    w = i;
                else
                    w = i - st.top() - 1;

                answer = max(answer, Arr[h] * w);
            }

            st.push(i);
        }

        cout << answer << '\n';
    }
    return 0;
}
