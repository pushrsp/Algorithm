#include <iostream>

using namespace std;

int N;

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        int a, b;
        cin>>a>>b;
        cout<<a+b<<endl;
    }
    return 0;
}