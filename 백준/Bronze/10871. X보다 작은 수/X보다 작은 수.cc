#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int N, X;

int main() {
    cin >> N >> X;

    vector<int> answer;
    for (int n = 0; n < N; ++n) {
        int a;
        cin >> a;

        if (a < X)
            answer.push_back(a);
    }

    for (auto a: answer)
        cout << a << " ";
    cout << endl;
}