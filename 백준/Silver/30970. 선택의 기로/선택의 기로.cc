#include <iostream>
#include <queue>

using namespace std;

struct S1 {
    int quality, price;

    bool operator<(const S1 &other) const {
        if (quality == other.quality)
            return price > other.price;

        return quality < other.quality;
    }
};

struct S2 {
    int quality, price;

    bool operator<(const S2 &other) const {
        if (price == other.price)
            return quality < other.quality;

        return price > other.price;
    }
};

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    priority_queue<S1> pq1;
    priority_queue<S2> pq2;

    int quality, price;
    for (int n = 0; n < N; ++n) {
        cin >> quality >> price;

        pq1.push({quality, price});
        pq2.push({quality, price});
    }

    for (int i = 0; i < 2; ++i) {
        cout << pq1.top().quality << ' ' << pq1.top().price << ' ';
        pq1.pop();
    }

    cout << '\n';

    for (int i = 0; i < 2; ++i) {
        cout << pq2.top().quality << ' ' << pq2.top().price << ' ';
        pq2.pop();
    }

    cout << '\n';
    return 0;
}