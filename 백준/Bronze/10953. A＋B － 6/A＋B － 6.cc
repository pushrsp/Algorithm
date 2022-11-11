#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t;
int a, b;
char tmp;

int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t; // t를 먼저 받아준다.

    for(int i=0;i<t;i++){
        cin >> a >> tmp >> b;
        cout << a+b << '\n';
    }
	
	return 0;
}