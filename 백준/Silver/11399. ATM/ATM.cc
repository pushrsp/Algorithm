#include <iostream>
#include <queue>

using namespace std;

int N;

int main() {
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;

        pq.push(n);
    }

    vector<int> answer;
    answer.push_back(pq.top());
    pq.pop();

    int idx = 0;
    while (!pq.empty()) {
        answer.push_back(pq.top() + answer[idx]);
        pq.pop();
        idx++;
    }

    int sum = 0;
    for (auto &n: answer)
        sum += n;

    cout << sum << endl;

    return 0;
}