#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int X, Y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> X >> Y;

    if (X == Y) {
        for (int n = 0; n < X; ++n)
            cout << "3";

        cout << '\n';
        return 0;
    }

    int lm = X * Y;
    vector<int> left, right;

    for (int i = 0; i <= lm; i += Y)
        left.push_back(i);
    for (int i = 0; i <= lm; i += X)
        right.push_back(i);

    string ret;
    if (right.size() > left.size()) {
        int l = 1;
        for (int r = 1; r < right.size(); ++r) {
            if (right[r] < left[l]) {
                ret.push_back('2');
            } else if (right[r] > left[l]) {
                ret.push_back('1');
                ret.push_back('2');
                l++;
            } else {
                ret.push_back('3');
                l++;
            }
        }
    } else {
        int r = 1;
        for (int l = 1; l < left.size(); ++l) {
            if (left[l] < right[r]) {
                ret.push_back('1');
            } else if (left[l] > right[r]) {
                ret.push_back('2');
                ret.push_back('1');
                r++;
            } else {
                ret.push_back('3');
                r++;
            }
        }
    }

    cout << ret << '\n';


    return 0;
}