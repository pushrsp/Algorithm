#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[91];
int odd = 0;
char mid;

int main() {
    string s;
    cin >> s;

    for (char c: s)
        arr[c]++;

    string ret = "";
    for (int i = 'Z'; i >= 'A'; --i) {
        if (arr[i] == 0)
            continue;

        if (arr[i] & 1) {
            mid = char(i);
            arr[i]--;
            odd++;
        }

        if (odd == 2)
            break;

        for (int j = 0; j < arr[i]; j += 2) {
            ret = char(i) + ret;
            ret += char(i);
        }
    }

    if (mid)
        ret.insert(ret.begin() + ret.size() / 2, mid);
    if (odd == 2)
        cout << "I'm Sorry Hansoo" << endl;
    else
        cout << ret << endl;
    return 0;
}