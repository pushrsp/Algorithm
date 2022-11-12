#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

vector<vector<int>> Answer(2);

struct Node {
    int x, y, index;
    Node *left, *right;
};

bool cmp_node(const Node &a, const Node &b) {
    return a.y > b.y;
}

void AddNode(Node &parent, Node &child) {
    if (child.x < parent.x) {
        if (parent.left == nullptr)
            parent.left = &child;
        else
            AddNode(*parent.left, child);
    } else {
        if (parent.right == nullptr)
            parent.right = &child;
        else
            AddNode(*parent.right, child);
    }
}

void PreOrder(Node *cur) {
    if (cur != nullptr) {
        Answer[0].push_back(cur->index);
        PreOrder(cur->left);
        PreOrder(cur->right);
    }
}

void PostOrder(Node *cur) {
    if (cur != nullptr) {
        PostOrder(cur->left);
        PostOrder(cur->right);
        Answer[1].push_back(cur->index);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<Node> nodes;
    for (int i = 0; i < nodeinfo.size(); ++i)
        nodes.push_back({nodeinfo[i][0], nodeinfo[i][1], i + 1, nullptr, nullptr});

    sort(nodes.begin(), nodes.end(), cmp_node);

    for (int i = 1; i < nodes.size(); ++i)
        AddNode(nodes[0], nodes[i]);

    PreOrder(&nodes[0]);
    PostOrder(&nodes[0]);
    return Answer;
}