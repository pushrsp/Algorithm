#include<iostream>
#include<algorithm>

using namespace std;

int n, m, pos[10001], answer = 0;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> pos[i];

    sort(pos, pos + n + 1);
    
    int pivot = 0;
    for (int i = 0; i <= n; ++i) {
        if (pos[i] == 0) {
            pivot = i;
            break;
        }
    }


    for (int i = 0; i < pivot; i += m)
        answer += abs(pos[i] * 2);


    for (int i = n; i > pivot; i -= m)
        answer += pos[i] * 2;


    answer -= max(abs(pos[0]), abs(pos[n]));

    cout << answer << endl;
    return 0;
}