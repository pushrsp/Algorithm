#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

#define INF 987654321
#define ll long long

using namespace std;

struct Lecture {
    int num;
    ll start, end;
};

struct Room {
    int num;
    ll end;

    bool operator<(const Room &other) const {
        return end > other.end;
    }
};

int N;

bool cmp(const Lecture &a, const Lecture &b) {
    if (a.start == b.start)
        return a.end < b.end;

    return a.start < b.start;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    vector<Lecture> lectures(N);
    for (int n = 0; n < N; ++n)
        cin >> lectures[n].num >> lectures[n].start >> lectures[n].end;

    sort(lectures.begin(), lectures.end(), cmp);

    int k = 1;
    map<int, int> m;
    priority_queue<Room> pq;

    for (auto &lecture: lectures) {
        if (pq.empty()) {
            m[lecture.num] = k;
            pq.push({k++, lecture.end});
        } else {
            if (pq.top().end <= lecture.start) {
                auto curr = pq.top();
                pq.pop();

                m[lecture.num] = curr.num;
                pq.push({curr.num, lecture.end});
            } else {
                m[lecture.num] = k;
                pq.push({k++, lecture.end});
            }
        }
    }

    cout << pq.size() << '\n';
    for (int n = 1; n <= N; ++n)
        cout << m[n] << '\n';

    return 0;
}