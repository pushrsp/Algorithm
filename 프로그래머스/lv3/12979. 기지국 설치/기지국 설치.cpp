#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <cmath>

using namespace std;

vector<int> Dist;

int solution(int n, vector<int> stations, int w) {
    int answer = 0;

    int prev = stations[0];
    if (prev - w > 1)
        Dist.push_back(prev - w - 1);

    for (int i = 1; i < stations.size(); ++i) {
        if (stations[i] - w <= prev + w + 1) {
            prev = stations[i];
        } else {
            Dist.push_back((stations[i] - w) - (prev + w + 1));
            prev = stations[i];
        }
    }

    if (prev + w < n)
        Dist.push_back(n - (prev + w));

    w *= 2;
    w += 1;
    int left = 0, right = 100000000, mid, cap;
    while (left < right) {
        mid = (left + right) / 2;
        cap = 0;

        for (int &dist: Dist) {
            cap += dist / w;
            if (dist % w)
                cap += 1;
        }

        if (mid >= cap) {
            answer = mid;
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return answer;
}