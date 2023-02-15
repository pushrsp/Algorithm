#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

#define MAX 1001

using namespace std;

int N, M;
unordered_map<string, string> Parent;
unordered_map<string, int> StrToIdx;
unordered_map<int, string> IdxToStr;
vector<int> Adj[MAX];
vector<string> Child[MAX];
bool Visited[MAX];

string GetParent(string s) {
    if (s == Parent[s])
        return s;

    return Parent[s] = GetParent(Parent[s]);
}

bool cmp(const int &a, const int &b) {
    return Adj[a].size() > Adj[b].size();
}

bool cmp_str(const string &a, const string &b) {
    return a < b;
}

void go(int now) {
    Visited[now] = true;

    for (auto &child: Adj[now]) {
        if (Visited[child])
            continue;

        Child[now].push_back(IdxToStr[child]);
        go(child);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    vector<string> people;
    string x, y;
    for (int i = 0; i < N; ++i) {
        cin >> x;

        people.push_back(x);
        StrToIdx.insert(make_pair(x, i));
        IdxToStr.insert(make_pair(i, x));
        Parent.insert(make_pair(x, x));
    }

    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> x >> y;

        Parent[x] = y;
        Adj[StrToIdx[y]].push_back(StrToIdx[x]);
    }

    for (int i = 0; i < people.size(); ++i)
        sort(Adj[i].begin(), Adj[i].end(), cmp);

    set<string> s;
    for (auto &pp: IdxToStr)
        s.insert(GetParent(pp.second));

    cout << s.size() << '\n';
    for (auto &super: s) {
        cout << super << ' ';
        go(StrToIdx[super]);
    }

    cout << '\n';

    sort(people.begin(), people.end());
    for (auto &pp: people) {
        cout << pp << ' ' << Child[StrToIdx[pp]].size() << ' ';

        sort(Child[StrToIdx[pp]].begin(), Child[StrToIdx[pp]].begin());

        for (auto &child: Child[StrToIdx[pp]])
            cout << child << ' ';

        cout << '\n';
    }
    return 0;
}