#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int arr[26];
int N;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;

        arr[s[0] - 'a']++;
    }

    string answer = "";
    for (int i = 0; i < 26; ++i) {
        if (arr[i] < 5)
            continue;

        answer += (char) (i + 'a');
    }

    if (answer.empty())
        cout << "PREDAJA" << endl;
    else
        cout << answer << endl;
    return 0;
}