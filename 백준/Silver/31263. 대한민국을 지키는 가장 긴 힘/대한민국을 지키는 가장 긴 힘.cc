#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define ll long long

using namespace std;

int N, Ret = INT32_MAX;
string S;

void go(int n, int count) {
    if (count > Ret)
        return;
    if (n >= N) {
        Ret = min(Ret, count);
        return;
    }

    string temp;
    //세개 자를 경우
    if (n + 3 <= N) {
        temp = S.substr(n, 3);

        if (temp[0] != '0' && 1 <= stoi(temp) && stoi(temp) <= 641)
            go(n + 3, count + 1);
    }

    //두개 자를 경우
    if (n + 2 <= N) {
        temp = S.substr(n, 2);

        if (temp[0] != '0' && 1 <= stoi(temp) && stoi(temp) <= 641)
            go(n + 2, count + 1);
    }

    //한개 자를 경우
    if (n + 1 <= N) {
        temp = S.substr(n, 1);

        if ('1' <= temp[0] && temp[0] <= '9')
            go(n + 1, count + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    cin >> S;

    go(0, 0);
    cout << Ret << '\n';

    return 0;
}