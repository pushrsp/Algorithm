#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int Nums[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
bool Visited[10];
vector<char> Oper;
vector<int> Temp;
vector<string> Answer;

bool calc(char oper, int n1, int n2) {
    if (oper == '<')
        return n1 < n2;
    else
        return n1 > n2;
}

void dfs(int cnt) {
    if (cnt == N + 1) {
        bool success = true;
        for (int i = 0; i < Oper.size(); ++i) {
            char oper = Oper[i];

            if (!calc(oper, Temp[i], Temp[i + 1]))
                success = false;
        }

        if (success) {
            string nums = "";

            for (int num: Temp)
                nums += (char) (num + '0');

            Answer.push_back(nums);
        }
        return;
    }

    for (int i = 0; i < 10; ++i) {
        if (Visited[i])
            continue;

        Visited[i] = true;
        Temp.push_back(Nums[i]);
        dfs(cnt + 1);
        Temp.pop_back();
        Visited[i] = false;
    }
}

bool cmp_str(const string &a, const string &b) {
    return a + b < b + a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    Oper = vector<char>(N);
    for (int n = 0; n < N; ++n)
        cin >> Oper[n];

    dfs(0);

    sort(Answer.begin(), Answer.end(), cmp_str);
    cout << Answer[Answer.size() - 1] << '\n';
    cout << Answer[0] << '\n';
    return 0;
}