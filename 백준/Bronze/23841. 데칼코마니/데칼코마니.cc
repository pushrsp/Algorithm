#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<string> Map, Ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    Map = vector<string>(N);
    for (int n = 0; n < N; ++n)
        cin >> Map[n];

    for (auto &s: Map) {
        string temp;
        for (int i = 0; i < s.length(); ++i)
            temp.push_back('.');

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != '.') {
                temp[i] = s[i];
                temp[M - 1 - i] = s[i];
            }
        }

        Ans.push_back(temp);
    }

    for (auto &ans: Ans)
        cout << ans << '\n';
    
    return 0;
}