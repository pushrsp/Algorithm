#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int N;
ll Scores[11];
bool Head[11];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    string num;
    for (int i = 0; i < N; ++i) {
        cin >> num;

        ll dist = 1;
        Head[num[0] - 'A'] = true;

        for (int j = num.length() - 1; j >= 0; --j) {
            Scores[num[j] - 'A'] += dist;
            dist *= 10;
        }
    }

    int mn = 0;
    for (int i = 0; i < 10; ++i) {
        if (!Head[i]) {
            mn = i;
            break;
        }
    }

    for (int i = 0; i < 10; ++i) {
        if (!Head[i] && Scores[i] < Scores[mn])
            mn = i;
    }

    Scores[mn] = 0;
    sort(Scores, Scores + 10, greater<ll>());

    ll ret = 0;
    for (int i = 0; i < 10; ++i)
        ret += (9 - i) * Scores[i];

    cout << ret << '\n';
    
    return 0;
}