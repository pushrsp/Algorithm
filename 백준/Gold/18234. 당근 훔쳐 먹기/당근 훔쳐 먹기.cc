#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

#define ll long long

using namespace std;

ll N, T;

bool cmp_pair(const pair<ll, ll>& a, const pair<ll, ll>& b)
{
    if (a.second == b.second)
        return a.first < b.first;

    return a.second < b.second;
}

int main() {
    cin >> N >> T;

    vector<pair<ll, ll>> carrots(N);
    for (int n = 0; n < N; n++)
        cin >> carrots[n].first >> carrots[n].second;
    
    sort(carrots.begin(), carrots.end(), cmp_pair);

    ll answer = 0;
    int idx = 0;
    for (int i = T - N; i < T; i++)
    {
        answer += carrots[idx].first + (carrots[idx].second * i);
        idx++;
    }

    cout << answer << endl;
    return 0;
}