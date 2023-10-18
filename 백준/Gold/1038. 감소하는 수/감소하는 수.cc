#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

int N;
vector<ll> Ans;

void go(string num, int max_len) {
    if (num.length() > max_len)
        return;
    if (!num.empty())
        Ans.push_back(stol(num));

    for (int i = 0; i <= 9; ++i) {
        if (!num.empty() && num[num.length() - 1] - '0' <= i)
            continue;

        go(num + to_string(i), max_len);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    if (N == 0) {
        cout << 0 << '\n';
        return 0;
    }
    
    go("", 10);

    if (N > Ans.size() - 1) {
        cout << -1 << '\n';
        return 0;
    }

    sort(Ans.begin(), Ans.end());

    cout << Ans[N] << '\n';

    return 0;
}