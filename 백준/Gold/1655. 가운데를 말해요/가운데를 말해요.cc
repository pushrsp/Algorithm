#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

#define ll long long

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    priority_queue<int, vector<int>, less<int>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;

        if (pq1.size() > pq2.size())
            pq2.push(n);
        else
            pq1.push(n);

        if (!pq1.empty() && !pq2.empty() && pq1.top() > pq2.top()) {
            int v1 = pq1.top(), v2 = pq2.top();
            pq1.pop(), pq2.pop();

            pq2.push(v1), pq1.push(v2);
        }

        cout << pq1.top() << '\n';
    }

    return 0;
}
