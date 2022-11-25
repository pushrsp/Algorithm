#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <set>

using namespace std;

#define ll long long

struct Trie {
    Trie() : Node(), child(0) {
    }

    void Add(string &s) {
        Trie *curr = this;

        for (char c: s) {
            curr->child++;
            if (curr->Node[c - 'a'] == nullptr)
                curr->Node[c - 'a'] = new Trie();

            curr = curr->Node[c - 'a'];
        }

        curr->child++;
    }

    int Find(string &s) {
        Trie *curr = this;
        for (char &c: s) {
            if (c == '?')
                return curr->child;

            curr = curr->Node[c - 'a'];
            if (curr == nullptr)
                return 0;
        }

        return curr->child;
    }

    int child;
    Trie *Node[26];
};

Trie TrieRoot[10000];
Trie ReTrieRoot[10000];

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for (auto word: words) {
        TrieRoot[word.length() - 1].Add(word);
        reverse(word.begin(), word.end());
        ReTrieRoot[word.length() - 1].Add(word);
    }

    for (auto query: queries) {
        if (query[0] != '?') {
            answer.push_back(TrieRoot[query.length() - 1].Find(query));
        } else {
            reverse(query.begin(), query.end());
            answer.push_back(ReTrieRoot[query.length() - 1].Find(query));
        }
    }

    return answer;
}