#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, Arr[11];
string DP[51];

string max_str(string a, string b) {
    if (a.length() > b.length())
        return a;
    else if (a.length() < b.length())
        return b;

    for (int i = 0; i < a.length(); ++i) {
        if (a[i] > b[i])
            return a;
        else if (a[i] < b[i])
            return b;
    }

    return a;
}

void go(int curr) {
    if (curr > M)
        return;

    string temp = "0";
    for (int i = N - 1; i > 0; --i) {
        if (curr < Arr[i])
            continue;
        if (DP[curr - Arr[i]] == "X") {
            temp = max_str(temp, to_string(i));
            continue;
        }

        string t1 = to_string(i);
        string t2 = to_string(i);

        for (int j = 0; j < (curr - Arr[i]) / Arr[0]; ++j)
            t1 += "0";
        for (int j = 0; j < DP[curr - Arr[i]].length(); ++j)
            t2 += DP[curr - Arr[i]][j];

        temp = max_str(temp, max_str(t1, t2));
    }

    DP[curr] = temp;
    go(curr + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int mn = 50;
    for (int i = 0; i < N; ++i) {
        cin >> Arr[i];
        mn = min(mn, Arr[i]);
    }

    cin >> M;

    for (int i = 0; i < mn; ++i)
        DP[i] = "X";

    go(mn);
    cout << DP[M] << '\n';
    return 0;
}