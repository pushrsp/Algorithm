#include <algorithm>
#include <iostream>

using namespace std;
int N;
pair<long long, long long> xa[100001];

int main() {
    cin >> N;
    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        cin >> xa[i].first >> xa[i].second;
        sum += xa[i].second;
    }
    sort(xa + 1, xa + N + 1);

    long long cur = 0;
    for (int i = 1; i <= N; i++) {
        cur += xa[i].second;
        if (cur >= (sum + 1) / 2) {
            cout << xa[i].first << endl;
            break;
        }
    }
}