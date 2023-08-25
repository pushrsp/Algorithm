#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <unordered_map>

#define ll long long

using namespace std;

string S;
int M;
ll DP[1001];
vector<pair<string, int>> Candidates;

ll go(int n) {
    if (n >= S.length())
        return 0;

    ll &ret = DP[n];
    if (ret != -1)
        return ret;

    ret = 0;
    for (auto &candidate: Candidates) {
        if (S.substr(n, candidate.first.length()) == candidate.first)
            ret = max(ret, go(n + candidate.first.length()) + candidate.second);
    }

    ret = max(ret, go(n + 1) + 1);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> S;

    cin >> M;

    string s;
    int score;
    for (int m = 0; m < M; ++m) {
        cin >> s >> score;
        if (s.length() >= score)
            continue;

        Candidates.emplace_back(s, score);
    }

    ::memset(DP, -1, sizeof(DP));

    cout << go(0) << '\n';
    return 0;
}