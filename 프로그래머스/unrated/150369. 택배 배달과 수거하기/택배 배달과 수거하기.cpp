#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <stack>

#define ll long long

using namespace std;

ll solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    ll answer = 0;

    while (!deliveries.empty() || !pickups.empty()) {
        while (!deliveries.empty() && deliveries.back() == 0)
            deliveries.pop_back();
        while (!pickups.empty() && pickups.back() == 0)
            pickups.pop_back();
        
        answer += max(deliveries.size() * 2, pickups.size() * 2);
        int deliv = 0;

        while (!deliveries.empty() && deliv <= cap) {
            if (deliv + deliveries.back() <= cap) {
                deliv += deliveries.back();
                deliveries.pop_back();
            } else {
                deliveries.back() -= (cap - deliv);
                break;
            }
        }

        int pickup = 0;
        while (!pickups.empty() && pickup <= cap) {
            if (pickup + pickups.back() <= cap) {
                pickup += pickups.back();
                pickups.pop_back();
            } else {
                pickups.back() -= (cap - pickup);
                break;
            }
        }
    }

    return answer;
}