#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define ll long long

using namespace std;

int N;
string S;

bool is_valid(string num) {
    return 1 <= stoi(num) && stoi(num) <= 641;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    cin >> S;

    int ret = 0, i;
    for (i = 0; i < N; ++i) {
        if ((i + 3 == N || (i + 3 < N && S[i + 3] != '0')) && is_valid(S.substr(i, 3)))
            i += 2;
        else if ((i + 2 == N || (i + 2 < N && S[i + 2] != '0')) && is_valid(S.substr(i, 2)))
            i += 1;

        ret += 1;
    }

    cout << ret << '\n';

    return 0;
}