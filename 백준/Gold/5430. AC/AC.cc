#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <sstream>

using namespace std;

int T;

deque<string> split(string input, char delimiter) {
    deque<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

int main() {
    cin >> T;

    for (int t = 0; t < T; ++t) {
        string p;
        cin >> p;

        int n;
        cin >> n;

        string x;
        cin >> x;

        x.erase(0, 1);
        x.erase(x.size() - 1, 1);

        deque<string> dq = split(x, ',');

        bool reverse = false, error = false;
        for (char i: p) {
            if (i == 'R') {
                if (reverse)
                    reverse = false;
                else
                    reverse = true;
            } else if (i == 'D') {
                if (dq.empty()) {
                    error = true;
                    break;
                }

                if (reverse)
                    dq.pop_back();
                else
                    dq.pop_front();
            }
        }

        if (error) {
            cout << "error" << endl;
            continue;
        }

        cout << '[';
        if (reverse && !dq.empty()) {
            for (auto o = dq.rbegin(); o != dq.rend(); o++) {
                if (o == dq.rend() - 1)
                    cout << *o;
                else
                    cout << *o << ',';
            }
        } else if (!reverse && !dq.empty()) {
            for (auto o = dq.begin(); o != dq.end(); o++) {
                if (o == dq.end() - 1)
                    cout << *o;
                else
                    cout << *o << ',';
            }
        }

        cout << ']' << endl;
    }

    return 0;
}