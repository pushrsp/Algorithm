#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>

using namespace std;

string N(int num, int n) {
    char code[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    string tmp = "";
    while (num / n != 0) {
        tmp = code[num % n] + tmp;
        num = num / n;
    }
    tmp = code[num % n] + tmp;
    return tmp;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string nums;
    int mx = t * m;

    int num = 0;
    while (nums.length() <= mx) {
        nums += N(num, n);
        num++;
    }

    for (int i = 0; i < nums.length(); ++i) {
        if (answer.length() == t)
            break;
        if (i % m + 1 == p)
            answer.push_back(nums[i]);
    }
    return answer;
}