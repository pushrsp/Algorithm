#include <string>
#include <vector>
#include <iostream>
#include <queue>

#define ll long long

using namespace std;

ll solution(int n, vector<int> times) {
    ll left = 1, right = 0, mid, cap;
    for (int &t: times)
        right = max(right, static_cast<ll>(t));

    right *= n;

    while (left < right) {
        mid = (left + right) / 2;
        cap = 0;

        for (int &t: times)
            cap += mid / static_cast<ll>(t);

        if (cap >= n)
            right = mid;
        else
            left = mid + 1;
    }

    return right;
}