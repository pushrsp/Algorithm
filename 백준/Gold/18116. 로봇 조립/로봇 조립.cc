#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define ll long long

using namespace std;

int N, Parent[1000001], Robot[1000001];

int get_parent(int n) {
    if (n == Parent[n])
        return n;

    return Parent[n] = get_parent(Parent[n]);
}

void merge(int a, int b) {
    a = get_parent(a), b = get_parent(b);

    if (a == b)
        return;

    if (a < b) {
        Robot[a] += Robot[b];
        Robot[b] = 0;
        Parent[b] = a;
    } else {
        Robot[b] += Robot[a];
        Robot[a] = 0;
        Parent[a] = b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int n = 1; n <= 1000000; ++n) {
        Parent[n] = n;
        Robot[n] = 1;
    }

    char cmd;
    int a, b;
    for (int n = 0; n < N; ++n) {
        cin >> cmd;

        if (cmd == 'I') {
            cin >> a >> b;
            merge(a, b);
        } else {
            cin >> a;

            cout << Robot[get_parent(a)] << '\n';
        }
    }

    return 0;
}