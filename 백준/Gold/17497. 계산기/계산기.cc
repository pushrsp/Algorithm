#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll N;

int main() {
    cin >> N;

    vector<char> vec;
    while (N) {
        if (N & 1) {
            N *= 2;
            vec.push_back('/');
        } else if (N & 2) {
            N -= 2;
            vec.push_back('+');
        } else {
            N /= 2;
            vec.push_back('*');
        }
    }

    if (vec.size() > 99) {
        cout << "-1" << endl;
    } else {
        cout << vec.size() << endl;
        while (!vec.empty()) {
            cout << "[" << vec.back() << "] ";
            vec.pop_back();
        }
    }


    return 0;
}