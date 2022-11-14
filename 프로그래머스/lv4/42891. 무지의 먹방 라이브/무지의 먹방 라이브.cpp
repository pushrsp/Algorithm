#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <regex>
#include <unordered_map>

#define ll long long

using namespace std;

bool cmp_pair(const pair<ll, int> &a, const pair<ll, int> &b) {
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    ll len = food_times.size();
    vector<pair<ll, int>> vec;

    for (int i = 0; i < len; ++i)
        vec.emplace_back(static_cast<ll>(food_times[i]), i + 1);

    sort(vec.begin(), vec.end(), greater<pair<ll, int>>());

    ll prev_height = 0;
    while (!vec.empty()) {
        auto now = vec.back();

        ll time = (now.first - prev_height) * vec.size();
        if (time == 0) {
            vec.pop_back();
            continue;
        }

        if (time <= k) {
            k -= time;
            prev_height = now.first;
        } else {
            k %= (ll) vec.size();
            sort(vec.begin(), vec.end(), cmp_pair);
            return vec[k].second;
        }

        vec.pop_back();
    }
    return -1;
}