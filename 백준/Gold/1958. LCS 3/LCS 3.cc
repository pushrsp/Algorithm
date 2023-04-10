#include<iostream>
#include<string>
#include<vector>

#define MAX 101

using namespace std;

int DP[MAX][MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s1, s2, s3;

    cin >> s1;
    cin >> s2;
    cin >> s3;

    for (int i = 1; i <= s1.length(); ++i) {
        for (int j = 1; j <= s2.length(); ++j) {
            for (int k = 1; k <= s3.length(); ++k) {
                if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
                    DP[i][j][k] = DP[i - 1][j - 1][k - 1] + 1;
                else
                    DP[i][j][k] = max(DP[i - 1][j][k], max(DP[i][j - 1][k], DP[i][j][k - 1]));
            }
        }
    }

    cout << DP[s1.length()][s2.length()][s3.length()] << '\n';
}