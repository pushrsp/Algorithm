#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;

int main() {
    cin >> N;

    struct Lecture {
        int id, from, to;
    };

    vector<Lecture> vec(N);
    for (int n = 0; n < N; ++n)
        cin >> vec[n].id >> vec[n].from >> vec[n].to;

    sort(vec.begin(), vec.end(), [&](const Lecture &a, const Lecture &b) {
        if (a.from == b.from)
            return a.to < b.to;

        return a.from < b.from;
    });

    int cnt = N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int n = 0; n < N; ++n) {
        pq.push(vec[n].to);

        if (!pq.empty() && pq.top() <= vec[n].from) {
            pq.pop();
            cnt--;
        }
    }

    cout << cnt << endl;
    return 0;
}