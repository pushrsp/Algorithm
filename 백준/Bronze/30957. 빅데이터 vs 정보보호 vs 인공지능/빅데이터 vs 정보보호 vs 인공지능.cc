#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

int N;
map<char, int> Order;

bool asc(const char &a, const char &b) {
    return Order[a] < Order[b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    Order.insert(make_pair('B', 0));
    Order.insert(make_pair('S', 1));
    Order.insert(make_pair('A', 2));

    cin >> N;

    string s;
    cin >> s;

    map<char, int> m;
    for (int n = 0; n < N; ++n)
        m[s[n]] += 1;

    int highest = 0;
    for (auto &p: m)
        highest = max(highest, p.second);

    vector<char> vec;
    for (auto &p: m) {
        if (p.second == highest)
            vec.push_back(p.first);
    }

    sort(vec.begin(), vec.end(), asc);

    if (vec.size() == 3)
        cout << "SCU" << '\n';
    else if (vec.size() == 2)
        cout << vec[0] << vec[1] << '\n';
    else
        cout << vec[0] << '\n';

    return 0;
}