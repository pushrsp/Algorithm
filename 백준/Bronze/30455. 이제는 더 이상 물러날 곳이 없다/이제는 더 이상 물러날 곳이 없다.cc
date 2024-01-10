#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int N, L;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    if (N % 2)
        cout << "Goose" << '\n';
    else
        cout << "Duck" << '\n';

    return 0;
}