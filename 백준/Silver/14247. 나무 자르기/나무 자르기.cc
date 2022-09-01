#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

#define ll long long

using namespace std;

int N;

bool cmp_pair(const pair<ll, ll>& a, const pair<ll, ll>& b)
{
    if (a.second == b.second)
        return a.first < b.first;

    return a.second < b.second;
}

int main() {
    cin >> N;

    vector<pair<ll, ll>> tree(N);
    for (int n = 0; n < N; n++)
        cin >> tree[n].first;
    
    for (int n = 0; n < N; n++)
        cin >> tree[n].second;
    
    sort(tree.begin(), tree.end(), cmp_pair);

    ll answer = 0;
    for (int n = 0; n < N; n++)
        answer += tree[n].first + (tree[n].second * n);
    
    cout << answer << endl;

    return 0;
}