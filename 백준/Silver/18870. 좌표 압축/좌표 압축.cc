#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>

#define MAX 1001
#define ll long long

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    set<int> s;
    vector<int> a, b;

    int n;
    for (int i = 0; i < N; ++i) {
        cin >> n;
        a.push_back(n);

        if (s.find(n) == s.end()) {
            b.push_back(n);
            s.insert(n);
        }
    }

    sort(b.begin(), b.end());

    for (int i = 0; i < a.size(); ++i)
        cout << ::lower_bound(b.begin(), b.end(), a[i]) - b.begin() << ' ';
    cout << '\n';
    
    return 0;
}