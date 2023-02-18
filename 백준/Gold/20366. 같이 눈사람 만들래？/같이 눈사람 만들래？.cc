#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define ll long long
#define INF 9876543210
#define MAX 601

using namespace std;

struct Node {
    int i, j;
    ll sum;

    bool operator<(const Node &other) const {
        return sum < other.sum;
    }
};

int N, Arr[MAX];
vector<Node> Candidates;

bool Valid(Node &a, Node &b) {
    if (a.i == b.i || a.i == b.j)
        return false;
    if (a.j == b.i || a.j == b.j)
        return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> Arr[i];

    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j)
            Candidates.push_back({i, j, Arr[i] + Arr[j]});
    }

    sort(Candidates.begin(), Candidates.end());

    ll ret = INF;
    for (int i = 0; i < Candidates.size(); ++i) {
        for (int j = i + 1; j < Candidates.size(); ++j) {
            if (Valid(Candidates[i], Candidates[j])) {
                ret = min(ret, static_cast<ll>(::abs(Candidates[i].sum - Candidates[j].sum)));
                break;
            }
        }
    }

    cout << ret << '\n';
    return 0;
}