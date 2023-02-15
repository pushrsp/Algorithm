#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001
#define INF 987654321

using namespace std;

int N;
string Answer;

void Change(string &s, int i) {
    s[i] == '0' ? s[i] = '1' : s[i] = '0';

    if (i - 1 >= 0)
        s[i - 1] == '0' ? s[i - 1] = '1' : s[i - 1] = '0';

    if (i + 1 < N)
        s[i + 1] == '0' ? s[i + 1] = '1' : s[i + 1] = '0';
}

int go(int i, string &s, int count) {
    if (i == N)
        return s == Answer ? count : INF;

    int ret;
    if (s[i - 1] == Answer[i - 1]) {
        ret = go(i + 1, s, count);
    } else {
        Change(s, i);
        ret = go(i + 1, s, count + 1);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    string s;
    cin >> s;
    cin >> Answer;

    if (s == Answer) {
        cout << 0 << '\n';
        return 0;
    }

    string temp = s;
    int ret = go(1, s, 0);
    if (ret == INF) {
        Change(temp, 0);
        ret = go(1, temp, 1);
    }

    if (ret == INF)
        cout << -1 << '\n';
    else
        cout << ret << '\n';

    return 0;
}