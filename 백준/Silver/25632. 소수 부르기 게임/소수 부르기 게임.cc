#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

int A, B, C, D, N[1001];
bool P[1001];
set<int> V;
vector<int> T, J;

void go(int t) {
    if (t % 2 == 0) {
        while (!T.empty() && V.find(T.back()) != V.end())
            T.pop_back();

        if (T.empty()) {
            cout << "yj" << '\n';
            ::exit(0);
        }

        V.insert(T.back());
        T.pop_back();
    } else {
        while (!J.empty() && V.find(J.back()) != V.end())
            J.pop_back();

        if (J.empty()) {
            cout << "yt" << '\n';
            ::exit(0);
        }

        V.insert(J.back());
        J.pop_back();
    }

    go(t + 1);
}

bool cmp(const int &a, const int &b) {
    return N[a] < N[b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> A >> B;
    cin >> C >> D;

    P[0] = P[1] = true;
    for (int i = 2; i < ::sqrt(1000); ++i) {
        if (!P[i]) {
            for (int j = i + i; j <= 1000; j += i)
                P[j] = true;
        }
    }

    for (int i = A; i <= B; ++i) {
        if (!P[i]) {
            T.push_back(i);
            N[i] += 1;
        }
    }

    for (int i = C; i <= D; ++i) {
        if (!P[i]) {
            J.push_back(i);
            N[i] += 1;
        }
    }

    sort(T.begin(), T.end(), cmp);
    sort(J.begin(), J.end(), cmp);

    go(0);

    return 0;
}