#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ll long long

using namespace std;

int N;
ll X;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> X;

    ll ret = 0;
    vector<ll> vec;
    ll num;

    for (int n = 0; n < N; ++n) {
        cin >> num;

        if (num == X) {
            ret += 1;
            continue;
        }

        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());

    int left = 0, right = vec.size() - 1, remain = vec.size();
    while (left < right) {
        if (vec[left] + vec[right] + (X / 2) >= X) {
            ret += 1;
            left++, right--;
            remain -= 2;
        } else {
            left++;
        }
    }

    if (remain >= 3)
        ret += remain / 3;

    cout << ret << '\n';
    
    return 0;
}