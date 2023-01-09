#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cmath>

#define MAX 51

using namespace std;

struct Node {
    int y, x;
    string value = "EMPTY";
    bool merged = false;

    Node *left = nullptr;
    Node *right = nullptr;
};

struct Table {
    Table() {
        for (int y = 0; y < MAX; ++y) {
            for (int x = 0; x < MAX; ++x) {
                Map[y][x].y = y, Map[y][x].x = x;
            }
        }
    }

    Node *GetParent(int y, int x) {
        if (!Map[y][x].merged)
            return &Map[y][x];

        Node *curr = &Map[y][x];
        while (curr->left != nullptr)
            curr = curr->left;

        return curr;
    }

    void Merge(int y1, int x1, int y2, int x2) {
        if (y1 == y2 && x1 == x2)
            return;

        Node *p1 = GetParent(y1, x1);
        Node *p2 = GetParent(y2, x2);

        if (p1->y == p2->y && p1->x == p2->x)
            return;

        Node *tail = p1;
        tail->merged = true;
        while (tail->right != nullptr)
            tail = tail->right, tail->merged = true;

        tail->right = p2;
        p2->left = tail;
        p2->merged = true;

        if (p1->value == "EMPTY" && p2->value != "EMPTY")
            p1->value = p2->value;
    }

    void Unmerge(int y, int x) {
        if (!Map[y][x].merged)
            return;

        Node *p = GetParent(y, x);
        string temp = p->value;

        stack<Node *> history;
        while (p->right != nullptr) {
            history.push(p);
            p = p->right;
        }

        history.push(p);
        while (!history.empty()) {
            history.top()->left = nullptr, history.top()->right = nullptr;
            history.top()->merged = false, history.top()->value = "EMPTY";
            history.pop();
        }

        Map[y][x].value = temp;
    }

    void Update(int y, int x, string &value) {
        GetParent(y, x)->value = value;
    }

    void Update(string &val1, string &val2) {
        for (int y = 1; y < MAX; ++y) {
            for (int x = 1; x < MAX; ++x) {
                Node *n = GetParent(y, x);
                if (n->value == val1)
                    n->value = val2;
            }
        }
    }

    string Print(int y, int x) {
        return GetParent(y, x)->value;
    }

    Node Map[MAX][MAX];
};

vector<string> Split(string &s, char c) {
    vector<string> ret;
    stringstream ss(s);
    string seg;

    while (getline(ss, seg, c))
        ret.push_back(seg);

    return ret;
}

vector<string> solution(vector<string> commands) {
    Table table;
    vector<string> answer;

    for (auto &command: commands) {
        vector<string> cmd = Split(command, ' ');
        if (cmd[0] == "UPDATE") {
            if (cmd.size() == 4) {
                int y = stoi(cmd[1]), x = stoi(cmd[2]);
                table.Update(y, x, cmd[3]);
            } else {
                table.Update(cmd[1], cmd[2]);
            }
        } else if (cmd[0] == "MERGE") {
            int y1 = stoi(cmd[1]), x1 = stoi(cmd[2]);
            int y2 = stoi(cmd[3]), x2 = stoi(cmd[4]);

            table.Merge(y1, x1, y2, x2);
        } else if (cmd[0] == "PRINT") {
            int y = stoi(cmd[1]), x = stoi(cmd[2]);
            answer.push_back(table.Print(y, x));
        } else {
            int y = stoi(cmd[1]), x = stoi(cmd[2]);
            table.Unmerge(y, x);
        }
    }

    return answer;
}