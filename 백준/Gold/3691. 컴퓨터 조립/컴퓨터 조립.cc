#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

#define ll long long

using namespace std;

struct P1 {
    ll price, quality;

    bool operator<(const P1 &other) const {
        return price > other.price;
    }
};

struct P2 {
    ll price, quality;
    string type;

    bool operator<(const P2 &other) const {
        return quality > other.quality;
    }
};

int T, N;
ll B;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N >> B;

        string type, name;
        int price, quality;
        map<string, priority_queue<P1>> m;

        for (int n = 0; n < N; ++n) {
            cin >> type >> name >> price >> quality;
            m[type].push({price, quality});
        }

        ll sum = 0;
        priority_queue<P2> pq;
        for (auto &p: m) {
            auto curr = p.second.top();
            p.second.pop();
            sum += curr.price;
            pq.push({curr.price, curr.quality, p.first});
        }

        while (true) {
            auto curr = pq.top();

            P2 next;
            bool change = false;
            while (true) {
                if (m[curr.type].empty())
                    break;

                next.price = m[curr.type].top().price;
                next.quality = m[curr.type].top().quality;
                next.type = curr.type;
                m[curr.type].pop();

                if (next.quality <= curr.quality)
                    continue;
                if (sum - curr.price + next.price > B)
                    break;

                change = true;
                break;
            }

            if (change) {
                sum -= curr.price;
                sum += next.price;
                pq.pop();
                pq.push(next);
            } else {
                break;
            }
        }

        ll ret = INT64_MAX;
        while (!pq.empty()) {
            ret = min(ret, pq.top().quality);
            pq.pop();
        }

        cout << ret << '\n';
    }

    return 0;
}