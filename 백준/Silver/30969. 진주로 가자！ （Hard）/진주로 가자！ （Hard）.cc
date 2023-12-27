#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    string s;
    ll price;

    int size = 0;
    vector<short> vec;
    vec.reserve(N);
    
    ll jinju = 0;
    for (int n = 0; n < N; ++n) {
        cin >> s >> price;

        if (s == "jinju")
            jinju = price;

        if (price > 1000) {
            size++;
        } else {
            vec.push_back(price);
        }
    }

    sort(vec.begin(), vec.end());

    cout << jinju << '\n';
    cout << vec.size() - (upper_bound(vec.begin(), vec.end(), jinju) - vec.begin()) + size << '\n';
    return 0;
}