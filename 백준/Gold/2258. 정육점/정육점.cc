#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

#define ll long long

using namespace std;

struct Info {
    ll meat, price;
};

ll N, M;

bool cmp_pair(const Info &a, const Info &b) {
    if (a.price == b.price)
        return a.meat > b.meat;

    return a.price < b.price;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    vector<Info> vec(N);
    for (int n = 0; n < N; ++n)
        cin >> vec[n].meat >> vec[n].price;

    sort(vec.begin(), vec.end(), cmp_pair);

    ll prev_price = 0, sum_price = 0, sum_meat = 0;
    for (int i = 0; i < N; ++i) {
        if (sum_meat < M) {
            if (prev_price == vec[i].price)
                sum_price += vec[i].price;
            else
                prev_price = sum_price = vec[i].price;
        } else {
            if (prev_price != vec[i].price && sum_price >= vec[i].price)
                prev_price = sum_price = vec[i].price;
        }

        sum_meat += vec[i].meat;
    }

    if (sum_meat < M)
        cout << -1 << '\n';
    else
        cout << sum_price << '\n';

    return 0;
}