#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

#define MAX 100001

using namespace std;

struct Trie {
    void Add(string &s) {
        Trie *curr = this;

        for (char c: s) {
            curr->child++;
            if (curr->nodes[c - 'a'] == nullptr)
                curr->nodes[c - 'a'] = new Trie();

            curr = curr->nodes[c - 'a'];
        }
    }

    int Find(string &s) {
        Trie *curr = this;

        for (char c: s) {
            if (c == '?')
                return curr->child;

            curr = curr->nodes[c - 'a'];
            if (curr == nullptr)
                return 0;
        }

        return curr->child;
    }

    Trie *nodes[26];
    int child = 0;
};

Trie Nodes1[MAX], Nodes2[MAX];

vector<int> solution(vector<string> words, vector<string> queries) {
    for (auto word: words) {
        Nodes1[word.length() - 1].Add(word);
        reverse(word.begin(), word.end());
        Nodes2[word.length() - 1].Add(word);
    }

    vector<int> answer;
    for (auto query: queries) {
        if (query[0] != '?') {
            answer.push_back(Nodes1[query.length() - 1].Find(query));
        } else {
            reverse(query.begin(), query.end());
            answer.push_back(Nodes2[query.length() - 1].Find(query));
        }
    }

    return answer;
}