#include <cstring>
#include <vector>
#include <deque>
#include <iostream>
#include <cmath>
#include <map>

#define ll long long

using namespace std;

int get(int a) {
    int ret = 0;
    int temp = a;
    while (temp) {
        ret += temp % 10;
        temp /= 10;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); ++i) {
        int a = s[i];
        int sum = get(a);

        for (int j = 0; j < sum; ++j) {
            cout << s[i];
        }
        cout << '\n';
    }
    return 0;
}