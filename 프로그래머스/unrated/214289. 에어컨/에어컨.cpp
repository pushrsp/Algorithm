#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

int DP[1001][3][100], Temperature, T1, T2, A, B;
vector<int> Onboard;

int get_offset(int curr) {
    if (curr == Temperature)
        return 0;
    else if (curr > Temperature)
        return -1;
    else
        return 1;
}

int go(int i, int cond, int cur_temperature) {
    if (i == Onboard.size())
        return 0;

    if (Onboard[i] && !(T1 <= cur_temperature && cur_temperature <= T2))
        return 9887654321;

    int &ret = DP[i][cond][cur_temperature + 11];
    if (ret != -1)
        return ret;

    ret = 9887654321;
    
    // 에어컨을 끌 경우
    int t4 = go(i + 1, 2, cur_temperature + get_offset(cur_temperature));
    ret = min(ret, t4);

    // 에어컨을 킬 경우
    int t1 = go(i + 1, 1, cur_temperature - 1) + A;
    ret = min(ret, t1);

    int t2 = go(i + 1, 1, cur_temperature + 1) + A;
    ret = min(ret, t2);

    int t3 = go(i + 1, 1, cur_temperature) + B;
    ret = min(ret, t3);

    return ret;
}

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    Temperature = temperature;
    T1 = t1, T2 = t2;
    A = a, B = b;
    Onboard = onboard;

    ::memset(DP, -1, sizeof(DP));

    int ret = go(0, 0, Temperature);

    return ret;
}