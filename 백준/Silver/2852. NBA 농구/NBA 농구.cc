#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int N, A = 0, B = 0, A_Time, B_Time;

string print(int a) {
    string d = "00" + to_string(a / 60);
    string e = "00" + to_string(a % 60);
    return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2);
}

int changeToInt(string a) {
    return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
}

void go(int &sum, string s, string prev) {
    sum += (changeToInt(s) - changeToInt(prev));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    string prev;
    for (int n = 0; n < N; ++n) {
        int team;
        string s;
        cin >> team >> s;

        if (A > B)
            go(A_Time, s, prev);
        else if (B > A)
            go(B_Time, s, prev);

        team == 1 ? A++ : B++;
        prev = s;
    }

    if (A > B)
        go(A_Time, "48:00", prev);
    else if (B > A)
        go(B_Time, "48:00", prev);


    cout << print(A_Time) << '\n';
    cout << print(B_Time) << '\n';
    return 0;
}