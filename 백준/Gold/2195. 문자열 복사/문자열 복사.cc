#include <iostream>
#include <set>
#include <vector>

using namespace std;

string S, P;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> S >> P;

    int ret = 0, idx = 0;
    while (idx < P.length()) {
        int max_len = 0;
        for (int j = 0; j < S.length(); ++j) {
            int offset = 0;
            while (P[idx + offset] == S[j + offset])
                offset++;

            max_len = max(max_len, offset);
        }

        idx += max_len;
        ret += 1;
    }

    cout << ret << '\n';

    return 0;
}