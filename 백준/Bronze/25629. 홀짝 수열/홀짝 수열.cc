#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

#define ll long long

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq1, pq2;

    int num;
    for (int n = 0; n < N; ++n) {
        cin >> num;

        if (num % 2)
            pq1.push(num);
        else
            pq2.push(num);
    }

    vector<int> ret;
    while (!pq1.empty() || !pq2.empty()) {
        if (!pq1.empty()) {
            ret.push_back(pq1.top());
            pq1.pop();

            if (ret.size() % 2 == 0) {
                cout << 0 << '\n';
                return 0;
            }
        }

        if (!pq2.empty()) {
            ret.push_back(pq2.top());
            pq2.pop();

            if (ret.size() % 2 == 1) {
                cout << 0 << '\n';
                return 0;
            }
        }
    }

    cout << 1 << '\n';

    return 0;
}