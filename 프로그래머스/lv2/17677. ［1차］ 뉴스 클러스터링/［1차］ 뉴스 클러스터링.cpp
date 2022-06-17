#include <iostream>
#include <vector>
#include <string>
#include <map>

#define MAX 65536

using namespace std;

bool isValid(char a) {
    if ('a' <= a && a <= 'z')
        return true;
    return false;
}

char toLower(char a) {
    if (isValid(a))
        return a;

    return a + 32;
}

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int solution(string a, string b) {
    int answer = 0;
    vector<string> total;
    map<string, int> A, B;

    for (int i = 0; i < a.size() - 1; ++i) {
        char nowStr = a[i];
        char nextStr = a[i + 1];

        nowStr = toLower(nowStr);
        nextStr = toLower(nextStr);

        if (!isValid(nowStr) || !isValid(nextStr))
            continue;

        string s = "";
        s += nowStr;
        s += nextStr;

        if (A[s] == 0)
            total.push_back(s);

        A[s]++;
    }

    for (int i = 0; i < b.size() - 1; ++i) {
        char nowStr = b[i];
        char nextStr = b[i + 1];

        nowStr = toLower(nowStr);
        nextStr = toLower(nextStr);

        if (!isValid(nowStr) || !isValid(nextStr))
            continue;

        string s = "";
        s += nowStr;
        s += nextStr;

        if (A[s] == 0 && B[s] == 0)
            total.push_back(s);

        B[s]++;
    }

    if (total.empty())
        return MAX;

    int gyo = 0, hap = 0;
    for (int i = 0; i < total.size(); ++i) {
        gyo += min(A[total[i]], B[total[i]]);
        hap += max(A[total[i]], B[total[i]]);
    }

    float d = (float) gyo / hap;
    answer = d * MAX;
    return answer;
}