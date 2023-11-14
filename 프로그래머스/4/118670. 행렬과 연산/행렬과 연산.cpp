#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <iostream>

using namespace std;

int N, M;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    N = rc.size();
    M = rc[0].size();

    deque<int> d1;
    for (int y = 0; y < N; ++y)
        d1.push_back(rc[y][0]);

    deque<deque<int>> d2;
    for (int y = 0; y < N; ++y) {
        deque<int> row;
        for (int x = 1; x < M - 1; ++x)
            row.push_back(rc[y][x]);

        d2.push_back(row);
    }

    deque<int> d3;
    for (int y = 0; y < N; ++y)
        d3.push_back(rc[y][M - 1]);

    int top = 0;
    for (auto &op: operations) {
        if (op == "Rotate") {
            //d1[first] -> d2[first][first]
            d2[top].push_front(d1.front());
            d1.pop_front();

            //d2[first][last] -> d3[first]
            d3.push_front(d2[top].back());
            d2[top].pop_back();

            //d3[last] -> d2[last][last]
            d2[(top + N - 1) % N].push_back(d3.back());
            d3.pop_back();

            //d2[last][first] -> d1[last]
            d1.push_back(d2[(top + N - 1) % N].front());
            d2[(top + N - 1) % N].pop_front();

        } else {
            d1.push_front(d1.back());
            d1.pop_back();

            d3.push_front(d3.back());
            d3.pop_back();

            top--;
            if (top < 0)
                top = N - 1;
        }
    }


    vector<vector<int>> answer(N, vector<int>(M));
    for (int y = 0; y < N; ++y) {
        answer[y][0] = d1[y];
        
        for (int x = 1; x < M - 1; ++x)
            answer[y][x] = d2[(y + top) % N][x - 1];

        answer[y][M - 1] = d3[y];
    }

    return answer;
}