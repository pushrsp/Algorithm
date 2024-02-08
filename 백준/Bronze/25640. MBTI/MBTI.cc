#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

#define ll long long

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string mbti;
    cin >> mbti;

    cin >> N;

    int ret = 0;
    string s;
    for (int n = 0; n < N; ++n) {
        cin >> s;

        if (mbti == s)
            ret += 1;
    }

    cout << ret << '\n';

    return 0;
}