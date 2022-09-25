#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int N;

int main() {
    cin >> N;

    int answer = 0;
    for (int n = 0; n < N; ++n) {
        string s;
        cin >> s;

        stack<char> st;
        for (auto c: s) {
            if (st.empty()) {
                st.push(c);
                continue;
            }

            if (st.top() == c)
                st.pop();
            else
                st.push(c);
        }

        if (st.empty())
            answer++;
    }

    cout << answer << endl;
    return 0;
}