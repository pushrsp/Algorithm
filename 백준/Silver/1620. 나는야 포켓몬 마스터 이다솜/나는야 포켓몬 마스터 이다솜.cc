#include<iostream>
#include<algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int N, M;
unordered_map<string, int> UM;
string Poketmon[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;

    for (int n = 0; n < N; ++n) {
        cin >> Poketmon[n];

        UM[Poketmon[n]] = n;
    }

    for (int m = 0; m < M; ++m) {
        string s;
        cin >> s;

        int idx = atoi(s.c_str());
        if (idx) {
            cout << Poketmon[idx - 1] << "\n";
        } else {
            cout << UM[s] + 1 << "\n";
        }
    }
    return 0;
}