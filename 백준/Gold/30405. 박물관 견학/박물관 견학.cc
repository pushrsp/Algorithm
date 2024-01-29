#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

#define ll long long

using namespace std;

int N, M, K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    vector<int> vec;
    for (int n = 0; n < N; ++n) {
        cin >> K;

        vector<int> temp(K);
        for (int k = 0; k < K; ++k)
            cin >> temp[k];

        vec.push_back(temp[0]);
        vec.push_back(temp.back());
    }

    sort(vec.begin(), vec.end());

    cout << vec[(vec.size() / 2) - 1] << '\n';

    return 0;
}