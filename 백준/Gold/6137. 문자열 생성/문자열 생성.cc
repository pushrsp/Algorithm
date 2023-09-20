#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    string s;
    char c;
    for (int n = 0; n < N; ++n) {
        cin >> c;
        s.push_back(c);
    }

    int left = 0, right = N - 1;
    string ret;
    while (left <= right) {
        if (left == right) {
            ret.push_back(s[left]);
            break;
        }

        if (s[left] < s[right]) {
            ret.push_back(s[left]);
            left++;
        } else if (s[left] > s[right]) {
            ret.push_back(s[right]);
            right--;
        } else {
            int tmp_left = left, tmp_right = right, choice = 1;
            while (tmp_left < tmp_right) {
                if (s[tmp_left] < s[tmp_right]) {
                    choice = 1;
                    break;
                } else if (s[tmp_left] > s[tmp_right]) {
                    choice = 2;
                    break;
                }

                tmp_left++, tmp_right--;
            }

            if (choice == 1) {
                ret.push_back(s[left]);
                left++;
            } else {
                ret.push_back(s[right]);
                right--;
            }
        }
    }

    int start = 0;
    while (start < ret.length()) {
        cout << ret.substr(start, 80) << '\n';
        start += 80;
    }
    return 0;
}