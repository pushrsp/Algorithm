#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string add_str(string &a, string &b) {
    string ret;
    int sum = 0;

    while (!a.empty() || !b.empty() || sum) {
        if (!a.empty()) {
            sum += a.back() - '0';
            a.pop_back();
        }

        if (!b.empty()) {
            sum += b.back() - '0';
            b.pop_back();
        }

        ret += (sum % 10) + '0';
        sum /= 10;
    }

    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    string a, b;
    cin >> a >> b;

    cout << add_str(a, b) << '\n';
    return 0;
}