#include <cstring>
#include <vector>
#include <deque>
#include <iostream>
#include <cmath>
#include <map>

#define ll long long

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    map<char, int> m;

    char track;
    for (int n = 0; n < N; ++n) {
        cin >> track;
        m[track] += 1;
    }

    cin >> track;
    cout << m[track] << '\n';

    return 0;
}