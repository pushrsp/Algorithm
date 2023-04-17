#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

#define MAX 1001

using namespace std;

int T, N;
int Arr[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; ++i)
            cin >> Arr[i];

        int sum1 = 0, sum2 = 0, ret = -987654321;
        for (int i = 1; i <= N; ++i) {
            sum1 += Arr[i];
            ret = max(ret, sum1 - sum2);
            sum2 = min(sum2, sum1);
        }

        cout << ret << '\n';
        
        ::memset(Arr, 0, sizeof(Arr));
    }
    return 0;
}