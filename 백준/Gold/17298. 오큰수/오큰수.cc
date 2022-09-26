#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int A;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A;

    stack<int> st;
    vector<int> vec(A);
    vector<int> arr(A, -1);

    for (int a = 0; a < A; ++a) {
        cin >> vec[a];

        while (!st.empty() && vec[st.top()] < vec[a]) {
            arr[st.top()] = vec[a];
            st.pop();
        }
        st.push(a);
    }

    for (auto a: arr)
        cout << a << " ";
    return 0;
}