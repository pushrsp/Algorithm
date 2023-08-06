#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;

bool desc_pair(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    vector<pair<int, int>> vec(N);
    for (int k = 1; k <= K; ++k) {
        cin >> vec[k - 1].first;
        vec[k - 1].second = k;
    }

    sort(vec.begin(), vec.end(), desc_pair);

    vector<int> answer;
    int left = 0, right = K - 1;
    while (left < right) {
        if (vec[left].first > vec[right].first) {
            answer.push_back(vec[left].second);
            answer.push_back(vec[right].second);
        } else {
            answer.push_back(vec[right].second);
            answer.push_back(vec[left].second);
        }

        vec[left].first--;
        vec[right].first--;

        if (vec[left].first == 0)
            left++;

        if (vec[right].first == 0)
            right--;
    }

    for (int i = 0; i < vec[left].first; ++i)
        answer.push_back(vec[left].second);

    vec[left].first = 0;

    for (int i = 0; i < vec[right].first; ++i)
        answer.push_back(vec[right].second);

    vec[right].first = 0;

    for (int i = 1; i < answer.size(); ++i) {
        if (answer[i] == answer[i - 1]) {
            cout << -1 << '\n';
            return 0;
        }
    }

    for (auto &ans: answer)
        cout << ans << ' ';

    return 0;
}