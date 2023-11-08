#include <iostream>
 
using namespace std;
 
int main(int argc, char const *argv[]) {
    int X, Y;
    cin >> X >> Y;
 
    // X가 양수일 경우(1사분면 or 4사분면)
    if (X > 0) {
 
        if (Y > 0) {
            cout << 1;
        } else {
            cout << 4;
        }
    }
    // X가 음수일 경우(2사분면 or 3사분면)
    else {
        if (Y > 0) {
            cout << 2;
        } else {
            cout << 3;
        }
    }
    return 0;
}