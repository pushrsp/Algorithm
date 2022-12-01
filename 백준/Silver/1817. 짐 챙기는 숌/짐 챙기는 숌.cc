#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;
    vector<int> books(N);

    for (int i = N - 1; i >= 0; i--)
        cin >> books[i];

    if (N == 0) {
        cout << 0 << '\n';
        return 0;
    }

    int answer = 0;
    while (!books.empty()) {
        int cur = M;
        while (!books.empty() && cur - books.back() >= 0)
            cur -= books.back(), books.pop_back();

        answer++;
    }

    cout << answer << '\n';
    return 0;
}