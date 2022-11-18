#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

struct TRIE {
    TRIE *Node[26];
    int level;

    void Insert(const char *str) {
        level++;
        if (*str == NULL)
            return;

        int Cur = *str - 'a';
        if (Node[Cur] == nullptr)
            Node[Cur] = new TRIE();

        Node[Cur]->Insert(str + 1);
    }

    int Find(const char *str, int count) {
        if (level == 1 || *str == NULL)
            return count;

        int index = *str - 'a';
        return Node[index]->Find(str + 1, count + 1);
    }
};

int solution(vector<string> words) {
    int answer = 0;
    TRIE *Root = new TRIE();

    for (auto &word: words)
        Root->Insert(word.c_str());

    for (auto &word: words)
        answer += Root->Find(word.c_str(), 0);

    return answer;
}