#include <iostream>
#include <map>
#include <algorithm>

#define INF 987654321

using namespace std;

int N, K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    string s;
    cin >> s;

    K--;

    string ret = s.substr(K);
    if ((N - K) % 2 == 0) {
        ret += s.substr(0, K);
    } else {
        string temp = s.substr(0, K);
        reverse(temp.begin(), temp.end());

        ret += temp;
    }

    cout << ret << '\n';

    return 0;
}