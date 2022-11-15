#include <string>
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

const int CACHE_HIT = 1;
const int CACHE_MISS = 5;

int solution(int cacheSize, vector<string> cities) {
    if (cacheSize == 0)
        return cities.size() * CACHE_MISS;

    int answer = 0;
    list<string> cache;
    for (auto &city: cities) {
        for (char &c: city) {
            if ('A' <= c && c <= 'Z')
                c += 32;
        }
    }

    for (auto &city: cities) {
        bool exist = false;
        auto iter = cache.begin();

        for (iter; iter != cache.end(); iter++) {
            if (*iter == city) {
                exist = true;
                answer += CACHE_HIT;
                cache.erase(iter);
                cache.push_back(city);
                break;
            }
        }

        if (!exist) {
            answer += CACHE_MISS;
            if (cache.size() == cacheSize) {
                cache.pop_front();
                cache.push_back(city);
            } else {
                cache.push_back(city);
            }
        }
    }

    return answer;
}