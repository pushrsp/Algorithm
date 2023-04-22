#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

#define MAX 51

using namespace std;

int N, M, K;
int Arr[MAX];

string max_str(const string &a, const string &b) {
    for (int i = 0; i < b.length(); ++i) {
        if (a[i] > b[i])
            return a;
        else if (a[i] < b[i])
            return b;
    }

    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < K; ++i)
        cin >> Arr[i];

    string ret;
    int left = 0, right = N * 2, mid, prev, cap;
    while (left <= right) {
        mid = (left + right) / 2;
        prev = 0;
        cap = 1;

        string curr = "1";
        for (int i = 1; i < K; ++i) {
            if (Arr[i] - Arr[prev] >= mid) {
                cap += 1;
                prev = i;
                curr += '1';

                if (cap == M)
                    break;
            } else {
                curr += '0';
            }
        }

        while (curr.length() < K)
            curr += '0';

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