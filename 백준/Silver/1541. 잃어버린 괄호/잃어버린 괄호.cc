#include<iostream>
#include<algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    int answer = 0;
    string temp = "";
    bool is_minus = false;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '+' || s[i] == '-') {
            if (is_minus)
                answer -= stoi(temp);
            else
                answer += stoi(temp);

            temp = "";
        } else {
            temp += s[i];
        }
        if (s[i] == '-')
            is_minus = true;
    }

    if (is_minus)
        answer -= stoi(temp);
    else
        answer += stoi(temp);

    cout << answer << '\n';

    return 0;
}