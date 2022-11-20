#include <iostream>
#include <vector>

using namespace std;

int T, N;

struct Trie {
    Trie *Node[10];
    bool finish = false;

    void Add(const char *str) {
        if (*str == NULL) {
            finish = true;
            return;
        }

        int num = *str - '0';
        if (Node[num] == nullptr)
            Node[num] = new Trie();

        Node[num]->Add(str + 1);
    }

    bool Find(const char *str) {
        if (*str == NULL)
            return false;

        if (finish)
            return true;

        int num = *str - '0';
        if (Node[num] == nullptr)
            return false;

        return Node[num]->Find(str + 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;

        vector<string> vec(N);
        Trie *root = new Trie();
        for (int n = 0; n < N; ++n) {
            cin >> vec[n];
            root->Add(vec[n].c_str());
        }

        bool success = true;
        for (auto &s: vec) {
            if (root->Find(s.c_str()))
                success = false;
        }

        if (success)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}