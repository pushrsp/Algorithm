#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    string num1, num2;
    cin >> num1 >> num2;

    int n1 = stoi(num1), n2 = stoi(num2);

    for (int i = num2.size() - 1; i >= 0; i--)
        cout << n1 * (num2[i] - '0') << endl;
    
    cout << n1 * n2 << endl;
    return 0;
}