#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<char> Oper;
vector<int> Num;
int N;
int ret = -987654321;

int calc(char oper, int n1, int n2) {
    if (oper == '+')
        return n1 + n2;
    else if (oper == '-')
        return n1 - n2;
    else
        return n1 * n2;
}

void dfs(int cnt, int n) {
    if (cnt == Oper.size()) {
        ret = max(ret, n);
        return;
    }

    dfs(cnt + 1, calc(Oper[cnt], n, Num[cnt + 1]));

    if (cnt + 2 <= Oper.size()) {
        int t = calc(Oper[cnt + 1], Num[cnt + 1], Num[cnt + 2]);
        dfs(cnt + 2, calc(Oper[cnt], n, t));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int n = 0; n < N; ++n) {
        char c;
        cin >> c;

        if (48 <= c && c <= 57)
            Num.push_back(c - '0');
        else
            Oper.push_back(c);
    }

    dfs(0, Num[0]);

    cout << ret << '\n';
    return 0;
}