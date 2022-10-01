#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    string b;
    cin >> b;

    string answer = "";
    for (char i: s) {
        answer += i;
        if (answer.size() >= b.size() && answer.substr(answer.size() - b.size(), b.size()) == b)
            answer.erase(answer.size() - b.size(), b.size());
    }


    if (!answer.empty())
        cout << answer << '\n';
    else
        cout << "FRULA" << '\n';
    return 0;
}