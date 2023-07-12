#include <iostream>
#include <vector>
#include <vector>

#define ll long long

using namespace std;

const int DP[10][10] = {
        {0, 4, 3, 3, 4, 3, 2, 3, 1, 2},
        {4, 0, 5, 3, 2, 5, 6, 1, 5, 4},
        {3, 5, 0, 2, 5, 4, 3, 4, 2, 3},
        {3, 3, 2, 0, 3, 2, 3, 2, 2, 1},
        {4, 2, 5, 3, 0, 3, 4, 3, 3, 2},
        {3, 5, 4, 2, 3, 0, 1, 4, 2, 1},
        {2, 6, 3, 3, 4, 1, 0, 5, 1, 2},
        {3, 1, 4, 2, 3, 4, 5, 0, 4, 3},
        {1, 5, 2, 2, 3, 2, 1, 4, 0, 1},
        {2, 4, 3, 1, 2, 1, 2, 3, 1, 0},
};
int K, P;
string N, X;

string getPad(string &a, string &b) {
    string ret = "";
    for (int i = a.length(); i < b.length(); ++i)
        ret.push_back('0');

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K >> P >> X;

    X = getPad(X, N) + X;

    ll ret = 0;
    int n = stoi(N);
    int c = stoi(X);
    for (int i = 1; i <= n; ++i) {
        if (i == c)
            continue;

        string s = to_string(i);
        s = getPad(s, X) + s;

        int pp = 0;
        for (int j = 0; j < X.length(); ++j) {
            int from = X[j] - '0', to = s[j] - '0';
            pp += DP[from][to];
        }

        if (pp <= P)
            ret += 1;
    }

    cout << ret << '\n';
    return 0;
}