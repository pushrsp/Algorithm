#include <iostream>
using namespace std;

int main(){
    int A, B, C;
    int N;
    int cnts[10] = {0,};

    cin >> A;
    cin >> B;
    cin >> C;

    N = A * B * C;
    while(N > 0)
    {
        cnts[N%10] += 1;
        N /= 10;
    }

    for(int i = 0; i<10;i++)
    {
        cout << cnts[i] << endl;
    }
    return 0;
}