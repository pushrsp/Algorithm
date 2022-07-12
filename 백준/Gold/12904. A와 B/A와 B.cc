#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

string S, T;

int main() {
    cin >> S >> T;

    stack<char> s;
    for (char &t: T)
        s.push(t);

    while (true) {
        if (S.size() == T.size())
            break;

        char c = T[T.size() - 1];

        T.pop_back();
        if (c == 'B')
            reverse(T.begin(), T.end());
    }

    if (S == T)
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}