#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll unsigned long long

using namespace std;

int N, M, K;
int A[51];

bool desc_pair(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    if (a.first == b.first)
        return a.second > b.second;

    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < K; ++i)
        cin >> A[i];

    string ret;
    int left = 0, right = N * 2, mid;
    while (left <= right) {
        mid = (left + right) / 2;

        string curr = "1";
        int prev = A[0], cap = 1;
        for (int i = 1; i < K; ++i) {
            if (A[i] - prev >= mid) {
                cap += 1;
                prev = A[i];
                curr += '1';

                if (cap == M)
                    break;
            } else {
                curr += '0';
            }
        }

        while (curr.length() < K)
            curr.push_back('0');

        if (cap == M) {
            left = mid + 1;
            ret = curr;
        } else {
            right = mid - 1;
        }
    }

    cout << ret << '\n';

    return 0;
}