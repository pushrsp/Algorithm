#include <string>
#include <vector>

#define ll long long

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (ll i = left; i <= right; i++) {
        ll d = i / n, r = i % n;
        if (i < (ll) n) {
            answer.push_back(i + 1);
            continue;
        }

        if (r <= d)
            answer.push_back(d + 1);
        else
            answer.push_back(d + 1 + (r - d));
    }

    return answer;
}