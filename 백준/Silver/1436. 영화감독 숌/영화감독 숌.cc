#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;

int main() {
    cin >> N;

    int pivot = 665;
    while (pivot++) {
        if (to_string(pivot).find("666") != string::npos)
            N--;

        if (N == 0)
            break;
    }

    cout << pivot << endl;
    return 0;
}