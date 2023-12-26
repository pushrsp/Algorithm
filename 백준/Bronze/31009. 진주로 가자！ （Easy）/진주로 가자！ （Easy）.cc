#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    map<string, int> m;

    string s;
    int price;
    for (int n = 0; n < N; ++n) {
        cin >> s >> price;

        m[s] = price;
    }

    price = m["jinju"];
    cout << price << '\n';

    int ret = 0;
    for (auto &p: m) {
        if (p.second > price)
            ret += 1;
    }

    cout << ret << '\n';
    
    return 0;
}