#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

#define ll long long
#define MAX 100001

using namespace std;

int N;
vector<pair<ll, ll>> Village;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    Village = vector<pair<ll, ll>>(N);

    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> Village[i].first >> Village[i].second;
        sum += Village[i].second;
    }

    sort(Village.begin(), Village.end());

    ll half = sum / 2;
    int ret = 0;
    while (ret < N) {
        sum -= Village[ret].second;
        if (sum <= half) {
            cout << Village[ret].first << '\n';
            return 0;
        }
        ret += 1;
    }

    return 0;
}