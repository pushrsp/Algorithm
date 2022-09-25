#include <iostream>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    for (char &c: s) {
        if ((65 <= c && c <= 90)) {
            int t = c - 'A';
            t = (t + 13) % 26;

            c = (char) (t + 'A');
        }

        if ((97 <= c && c <= 122)) {
            int t = c - 'a';
            t = (t + 13) % 26;

            c = (char) (t + 'a');
        }
    }

    cout << s << " ";
    return 0;
}