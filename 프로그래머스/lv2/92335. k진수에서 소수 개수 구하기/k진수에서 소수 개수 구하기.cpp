#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
#include <vector>
#include <set>
#include <cmath>

#define ll long long

using namespace std;

string convert_num(int num, int n) {
    char code[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    string tmp = "";
    while (num / n != 0) {
        tmp = code[num % n] + tmp;
        num = num / n;
    }
    tmp = code[num % n] + tmp;
    return tmp;
}

bool IsPrime(ll n) {
    if (n == 0 || n == 1)
        return false;

    for (ll i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string num = convert_num(n, k);
    string temp;

    for (char &i: num) {
        if (i != '0') {
            temp += i;
        } else {
            if (!temp.empty() && IsPrime(stoll(temp)))
                answer++;

            temp.clear();
        }
    }

    if (!temp.empty() && IsPrime(stoll(temp)))
        answer++;

    return answer;
}