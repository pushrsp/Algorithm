#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> zero;
    vector<int> one;

    char cur = s[0];
    if (cur == '0')
        zero.push_back(0);
    else
        one.push_back(1);

    for (char i: s) {
        if (cur != i) {
            if (i == '0')
                zero.push_back(0);
            else
                one.push_back(1);

            cur = i;
        }
    }

    if (zero.size() > one.size())
        cout << one.size() << endl;
    else
        cout << zero.size() << endl;

    return 0;
}