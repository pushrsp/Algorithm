#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, MAX = 0;
vector<string> s;
vector<int> t;
vector<char> a;
bool visited[26] = {false};
bool num_visited[10] = {false};

void calc() {
    int sum = 0;
    int temp[26] = {0};

    for (int i = 0; i < a.size(); i++)
        temp[a[i] - 'A'] = t[i];

    for (int i = 0; i < s.size(); ++i) {
        int num = 0;
        for (auto k: s[i]) {
            num *= 10;
            num += temp[k - 'A'];
        }

        sum += num;
    }

    if (sum > MAX)
        MAX = sum;
}

void perm(int cnt) {
    if (cnt == 10) {
        calc();
        return;
    } else {
        for (int i = 10 - a.size(); i < 10; i++) {
            if (!num_visited[i]) {
                num_visited[i] = true;
                t.push_back(i);
                perm(cnt + 1);
                t.pop_back();
                num_visited[i] = false;
            }
        }
    }
}

int main() {
    cin >> N;

    s = vector<string>(N);

    for (int i = 0; i < N; ++i) {
        cin >> s[i];

        for (char k: s[i]) {
            if (!visited[k - 'A']) {
                visited[k - 'A'] = true;
                a.push_back(k);
            }
        }
    }

    perm(10 - a.size());

    cout << MAX << endl;
    return 0;
}