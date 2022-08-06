#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;

int main() {
    cin >> N;

    for (int n = 1; n <= N; ++n) {
        string s;
        for (int i = 1; i <= n; ++i)
            s += "*";

        cout << s << endl;
    }

    return 0;
}