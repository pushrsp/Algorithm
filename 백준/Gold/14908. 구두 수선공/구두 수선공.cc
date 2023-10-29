#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define ll long long

using namespace std;

struct Job {
    double result;
    int i;
};

int N;

bool cmp(const Job &a, const Job &b) {
    if (a.result == b.result)
        return a.i < b.i;

    return a.result < b.result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    vector<Job> jobs(N);
    for (int n = 0; n < N; ++n) {
        double a, b;
        cin >> a >> b;

        jobs[n].result = a / b;
        jobs[n].i = n;
    }

    sort(jobs.begin(), jobs.end(), cmp);

    for (auto &job: jobs)
        cout << job.i + 1 << ' ';

    cout << '\n';

    return 0;
}