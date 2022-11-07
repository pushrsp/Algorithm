#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <queue>
#include <algorithm>

#define ll long long

using namespace std;

/**
 * a: 도시 건설하는데 필요한 금
 * b: 도시 건설하는데 필요한 은
 * g: 금
 * s: 은
 * w: 최대 무게
 * t: 편도 시간
 */

struct City {
    ll g, s, w, t;
};

bool search_city(ll mid, int a, int b, vector<City> &cities) {
    int now_gold = 0, now_silver = 0, now_carry = 0;
    for (City &city: cities) {
        ll t = city.t * 2;
        ll count = mid / t;

        if (mid % t >= city.t)
            count++;

        ll weight = city.w * count;
        now_gold += min(city.g, weight);
        now_silver += min(city.s, weight);
        now_carry += min(city.g + city.s, weight);
    }

    if (now_gold >= a && now_silver >= b && now_carry >= a + b)
        return true;

    return false;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    vector<City> cities;

    for (int i = 0; i < g.size(); ++i) {
        if (g[i] == 0 && s[i] == 0)
            continue;

        cities.push_back({(ll) g[i], (ll) s[i], (ll) w[i], (ll) t[i]});
    }

    ll left = 0, right = 10e14 * 3, mid;
    while (left <= right) {
        mid = (left + right) / 2;

        if (search_city(mid, a, b, cities)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return answer;
}