#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

#define MAX 1001

using namespace std;

struct Person {
    string name;
    vector<string> children;

    bool operator<(const Person &other) const {
        return name < other.name;
    }
};

int N, M, InDegree[MAX];
unordered_map<string, int> StrToIdx;
unordered_map<int, string> IdxToStr;
vector<int> Adj[MAX], Answer[MAX];

void Sort(int start) {
    queue<int> q;

    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int &next: Adj[cur]) {
            InDegree[next]--;

            if (InDegree[next] == 0) {
                Answer[cur].push_back(next);
                q.push(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    string x, y;
    for (int i = 0; i < N; ++i) {
        cin >> x;

        StrToIdx.insert(make_pair(x, i));
        IdxToStr.insert(make_pair(i, x));
    }

    cin >> M;

    for (int i = 0; i < M; ++i) {
        cin >> x >> y;

        Adj[StrToIdx[y]].push_back(StrToIdx[x]);
        InDegree[StrToIdx[x]]++;
    }

    vector<string> parent;
    for (int i = 0; i < N; ++i) {
        if (InDegree[i] == 0)
            parent.push_back(IdxToStr[i]);
    }

    sort(parent.begin(), parent.end());

    cout << parent.size() << '\n';

    for (auto &p: parent) {
        cout << p << ' ';
        Sort(StrToIdx[p]);
    }

    cout << '\n';

    vector<Person> ret;
    for (int i = 0; i < N; ++i) {
        Person p;
        p.name = IdxToStr[i];

        for (auto &child: Answer[i])
            p.children.push_back(IdxToStr[child]);

        sort(p.children.begin(), p.children.end());
        ret.push_back(p);
    }

    sort(ret.begin(), ret.end());

    for (auto &answer: ret) {
        cout << answer.name << ' ' << answer.children.size() << ' ';

        for (auto &child: answer.children)
            cout << child << ' ';

        cout << '\n';
    }

    return 0;
}