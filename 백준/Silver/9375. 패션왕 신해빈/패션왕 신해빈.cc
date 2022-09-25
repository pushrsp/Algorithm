#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

#define ll long long

using namespace std;

int T;
string name, type;

int main() {
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        unordered_map<string, int> m;
        for (int n = 0; n < N; ++n) {
            cin >> name >> type;
            m[type]++;
        }

        ll answer = 1;
        for (auto it: m)
            answer *= ((ll) it.second + 1);

        cout << answer - 1 << endl;
    }
    return 0;
}