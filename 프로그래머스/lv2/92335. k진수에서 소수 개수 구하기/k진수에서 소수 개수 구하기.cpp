#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

bool is_prime(ll n) {
    if (n < 2) return false;

    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0)
            return false;
    }

    return true;
}

string conversion(int n, int k) {
    string ret = "";

    while (n) {
        ret += to_string(n % k);
        n /= k;
    }

    return string(ret.rbegin(), ret.rend());
}

vector<ll> split(string &s, char del) {
    vector<ll> vec;
    string t;

    for (char i: s) {
        if (i != del) {
            t += i;
        } else {
            if (t.size() > 0)
                vec.push_back(atoll(t.c_str()));

            t = "";
        }
    }

    if (!t.empty())
        vec.push_back(atoll(t.c_str()));

    return vec;
}

int solution(int n, int k) {
    int answer = 0;
    string s = conversion(n, k);
    vector<ll> vec = split(s, '0');

    for (ll v: vec) {
        if (is_prime(v))
            answer++;
    }

    
    return answer;
}