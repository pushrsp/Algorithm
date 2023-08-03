#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N, A, B;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> A >> B;

    deque<int> dq;

    for (int a = 1; a < A; ++a)
        dq.push_back(a);

    dq.push_back(max(A, B));

    for (int b = B - 1; b >= 1; --b)
        dq.push_back(b);

    if (dq.size() > N) {
        cout << -1;
        return 0;
    }

    int front = dq.front();
    dq.pop_front();

    int size = dq.size();
    for (int i = 0; i < N - size - 1; ++i)
        dq.push_front(1);

    dq.push_front(front);

    for (auto &ans: dq)
        cout << ans << ' ';

    return 0;
}