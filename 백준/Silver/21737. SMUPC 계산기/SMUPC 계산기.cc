#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <map>

#define ll long long

using namespace std;

int N;

void calc(char op, ll n1, ll n2) {

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    string s;
    cin >> s;

    queue<char> ops;
    queue<ll> nums;
    string temp;
    for (int i = 0; i < s.length(); ++i) {
        if ('0' <= s[i] && s[i] <= '9') {
            temp.push_back(s[i]);
        } else {
            if (!temp.empty())
                nums.push(stol(temp));

            temp.clear();

            ops.push(s[i]);
        }
    }

    ll ret = nums.front();
    nums.pop();

    bool called = false;
    while (!nums.empty() && !ops.empty()) {
        ll n = 0;

        char op = ops.front();
        ops.pop();

        if (op != 'C') {
            n = nums.front();
            nums.pop();
        }

        if (op == 'S') {
            ret -= n;
        } else if (op == 'M') {
            ret *= n;
        } else if (op == 'U') {
            ret /= n;
        } else if (op == 'P') {
            ret += n;
        } else {
            called = true;
            cout << ret << ' ';
        }
    }

    while (!ops.empty()) {
        char op = ops.front();
        ops.pop();

        if (op == 'C') {
            called = true;
            cout << ret << ' ';
        }
    }

    if (!called)
        cout << "NO OUTPUT";

    cout << '\n';

    return 0;
}