#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, A[100001], B[100001], Num[100001], Ans = INT32_MAX;
bool Visited[4];
vector<int> Temp;

int calc() {
    int i, j, k = 0, pos[4][4] = {{0}}, cnt1 = 0, cnt2 = 0;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < Num[Temp[i]]; j++)
            B[k++] = Temp[i];
    }

    for (i = 0; i < N; i++)
        pos[B[i]][A[i]]++;

    return pos[1][2] + pos[1][3] + max(pos[2][3], pos[3][2]);
}

void go(int count) {
    if (count == 3) {
        Ans = min(Ans, calc());
        return;
    }

    for (int i = 1; i <= 3; i++) {
        if (Visited[i])
            continue;

        Visited[i] = true;
        Temp.push_back(i);

        go(count + 1);

        Visited[i] = false;
        Temp.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for (int n = 0; n < N; n++) {
        cin >> A[n];
        Num[A[n]]++;
    }

    go(0);

    cout << Ans << '\n';

    return 0;
}