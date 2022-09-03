#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int N, C;

int main() {
    cin >> N;
    
    int min_num = INT32_MAX;
    int max_num = -INT32_MAX;
    
    for(int n = 0; n < N; n++) {
        int c;
        cin >> c;
        
        min_num = min(min_num, c);
        max_num = max(max_num, c);
    }
    
    cout << min_num << " "<< max_num << endl;
    return 0;
}