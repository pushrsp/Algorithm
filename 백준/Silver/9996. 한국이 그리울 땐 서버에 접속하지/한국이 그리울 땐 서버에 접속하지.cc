#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int N;
vector<string> Vec;

vector<string> split(string &s, char c) {
    vector<string> ret;
    stringstream ss(s);
    string segment;

    while (getline(ss, segment, c))
        ret.push_back(segment);

    return ret;
}

int main() {
    cin >> N;

    string cmp;
    cin >> cmp;

    Vec = vector<string>(N);
    for (int i = 0; i < N; ++i)
        cin >> Vec[i];

    vector<string> d = split(cmp, '*');
    string head = d[0], tail = d[1];

    for (auto &s: Vec) {
        if (s.size() < head.size() + tail.size()) {
            cout << "NE" << endl;
            continue;
        }

        bool success = true;
        for (int i = 0; i < head.size(); ++i) {
            if (s[i] != head[i])
                success = false;
        }

        int start = s.size() - tail.size();
        for (int i = start; i < s.size(); ++i) {
            if (s[i] != tail[i - start])
                success = false;
        }

        if (success)
            cout << "DA" << endl;
        else
            cout << "NE" << endl;
    }
    return 0;
}