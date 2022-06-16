#include <iostream>
#include <vector>

using namespace std;

string ToBinary(int n) {
    string result = "";
    for (int i = 1; n > 0; i *= 10) {
        int bin = n % 2;
        result = to_string(bin * i) + result;
        n /= 2;
    }

    return result;
}

int ToDecimal(int n) {
    int result = 0, mul = 1;
    while (n > 0) {
        if (n % 2 != 0)
            result += mul;

        mul *= 2;
        n /= 10;
    }

    return result;
}

int get_num(string r) {
    int num = 0;
    for (int i = 0; i < r.size(); ++i) {
        if (r[i] == '1')
            num++;
    }

    return num;
}

int solution(int n) {
    int answer;
    int num = get_num(ToBinary(n));

    for (int i = n + 1;; ++i) {
        if (num == get_num(ToBinary(i))) {
            answer = i;
            break;
        }

    }

    return answer;
}