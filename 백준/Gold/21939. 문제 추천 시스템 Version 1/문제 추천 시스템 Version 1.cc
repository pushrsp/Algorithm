#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_map>

using namespace std;

struct Hard {
    int p, l;

    bool operator<(const Hard other) const {
        if (l == other.l)
            return p < other.p;

        return l < other.l;
    }
};

struct Easy {
    int p, l;

    bool operator<(const Easy other) const {
        if (l == other.l)
            return p > other.p;

        return l > other.l;
    }
};

int N, M, L, P;
bool Solved[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;


    priority_queue<Hard> h_pq;
    priority_queue<Easy> e_pq;
    unordered_map<int, vector<int>> um;

    for (int n = 0; n < N; ++n) {
        cin >> P >> L;

        um[P].push_back(L);

        h_pq.push({P, L});
        e_pq.push({P, L});
    }

    cin >> M;

    set<pair<int, int>> solved;
    int p, l;
    string cmd;

    for (int m = 0; m < M; ++m) {
        cin >> cmd;

        if (cmd == "recommend") {
            cin >> p;

            if (p == -1) {
                while (!e_pq.empty()) {
                    auto curr = e_pq.top();
                    if (solved.find(make_pair(curr.p, curr.l)) != solved.end()) {
                        e_pq.pop();
                        continue;
                    }

                    cout << curr.p << '\n';
                    break;
                }
            } else {
                while (!h_pq.empty()) {
                    auto curr = h_pq.top();
                    if (solved.find(make_pair(curr.p, curr.l)) != solved.end()) {
                        h_pq.pop();
                        continue;
                    }

                    cout << curr.p << '\n';
                    break;
                }
            }
        } else if (cmd == "solved") {
            cin >> p;

            while (!um[p].empty()) {
                solved.insert(make_pair(p, um[p].back()));
                um[p].pop_back();
            }

        } else {
            cin >> p >> l;

            um[p].push_back(l);
            e_pq.push({p, l});
            h_pq.push({p, l});
        }
    }
    return 0;
}