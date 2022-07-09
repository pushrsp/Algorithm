#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N, K;
string S;

int main() {
    cin >> N >> K >> S;

    deque<char> dq;
    for (int i = 0; i < S.size(); ++i) {

        while (K > 0 && !dq.empty() && dq.back() < S[i]) {
            dq.pop_back();
            K--;
        }
        dq.push_back(S[i]);
    }

    for (int i = 0; i < dq.size() - K; ++i) {
        cout << dq[i];
    }
    cout << endl;

    return 0;
}