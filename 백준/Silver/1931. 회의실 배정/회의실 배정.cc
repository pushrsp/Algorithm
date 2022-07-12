#include <iostream>
#include <queue>

using namespace std;

struct Meeting {
    bool operator<(const Meeting &other) const {
        if (end == other.end)
            return start > other.start;

        return end > other.end;
    }

    int start, end;
};

int N;

int main() {
    cin >> N;


    priority_queue<Meeting> m;
    for (int n = 0; n < N; ++n) {
        Meeting meeting{};
        cin >> meeting.start >> meeting.end;

        m.push(meeting);
    }

    Meeting cur = m.top();
    m.pop();

    int cnt = 1;
    while (!m.empty()) {
        Meeting now = m.top();
        m.pop();

        if (now.start >= cur.end) {
            cur = now;
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}