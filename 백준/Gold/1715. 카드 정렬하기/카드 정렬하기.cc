#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;

int main() {
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int n = 0; n < N; ++n) {
        int c;
        cin >> c;

        pq.push(c);
    }

    int result = 0;
    while (!pq.empty()) {
        if (pq.size() == 1)
            break;
        
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        result += a;
        result += b;
        pq.push(a + b);
    }

    cout << result << endl;
    return 0;
}