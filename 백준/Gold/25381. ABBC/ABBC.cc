#include <iostream>
#include <algorithm>
#include <queue>

#define ll long long

using namespace std;

string S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> S;

    int ret = 0;
    queue<int> aq, bq;
    for (int i = 0; i < S.length(); ++i) {
        if (S[i] == 'A') {
            aq.push(i);
        } else if (S[i] == 'B') {
            bq.push(i);
        } else {
            if (!bq.empty() && bq.front() < i) {
                ret += 1;
                bq.pop();
            }
        }
    }

    while (!aq.empty() && !bq.empty()) {
        if (aq.front() < bq.front()) {
            ret += 1;
            aq.pop();
            bq.pop();
        } else {
            bq.pop();
        }
    }

    cout << ret << '\n';
    
    return 0;
}