#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

string S;
vector<string> Vec(2);
int DP[2][21][101];

int go(int v_i, int s_i, int i_i, string temp) {
    if (S == temp)
        return 1;
    if (temp.length() == S.length())
        return 0;

    int &ret = DP[v_i][s_i][i_i];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = i_i; i < Vec[v_i].length(); ++i) {
        if (Vec[v_i][i] == S[s_i])
            ret += go((v_i + 1) % 2, s_i + 1, i + 1, temp + S[s_i]);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> S;
    for (int i = 0; i < 2; ++i)
        cin >> Vec[i];

    ::memset(DP, -1, sizeof(DP));

    int ret = go(0, 0, 0, "");
    ret += go(1, 0, 0, "");

    cout << ret << '\n';
    
    return 0;
}