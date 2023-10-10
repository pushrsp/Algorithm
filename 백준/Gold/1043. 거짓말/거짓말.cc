#include <iostream>
#include <set>
#include <vector>
#include <vector>

#define ll long long

using namespace std;

int N, M, Parent[51], Party[51][51], Nums[51];

int get_parent(int i) {
    if (Parent[i] == i)
        return i;

    return Parent[i] = get_parent(Parent[i]);
}

void merge(int a, int b) {
    a = get_parent(a), b = get_parent(b);

    if (a < b)
        Parent[b] = a;
    else
        Parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int n = 0; n <= N; ++n)
        Parent[n] = n;

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        Parent[n] = 0;
    }

    for (int m = 0; m < M; ++m) {
        cin >> Nums[m];
        cin >> Party[m][0];

        for (int i = 1; i < Nums[m]; ++i) {
            cin >> Party[m][i];
            merge(Party[m][0], Party[m][i]);
        }
    }

    int ret = M;
    for (int m = 0; m < M; ++m) {
        for (int i = 0; i < Nums[m]; ++i) {
            if (get_parent(Party[m][i]) == 0) {
                ret--;
                break;
            }
        }
    }

    cout << ret << '\n';
    return 0;
}