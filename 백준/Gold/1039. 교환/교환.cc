#include <iostream>
#include <set>
#include <queue>
#include <algorithm>

#define INF 987654321
#define ll long long

using namespace std;

string N;
int K;
int DP[1000001][11];

int go(int count, string s) {
    if (count == K)
        return stoi(s);

    int &ret = DP[stoi(s)][count];
    if (ret)
        return ret;

    for (int i = 0; i < N.length(); ++i) {
        for (int j = i + 1; j < N.length(); ++j) {
            if (i == 0 && s[j] == '0')
                continue;

            swap(s[i], s[j]);
            ret = max(ret, go(count + 1, s));
            swap(s[i], s[j]);
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;
    int answer = go(0, N);

    if (answer == 0)
        cout << -1 << '\n';
    else
        cout << answer << '\n';
    return 0;
}