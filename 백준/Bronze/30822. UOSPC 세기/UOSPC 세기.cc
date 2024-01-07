#include <iostream>
#include <map>
#include <algorithm>

#define INF 987654321

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    map<char, int> m;

    char c;
    for (int n = 0; n < N; ++n) {
        cin >> c;
        m[c] += 1;
    }

    int ret = min(m['u'], m['o']);
    ret = min(ret, m['s']);
    ret = min(ret, m['p']);
    ret = min(ret, m['c']);

    cout << ret << '\n';

    return 0;
}