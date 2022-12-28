#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX 101

using namespace std;

int Cards[MAX], Visited[MAX], Finished[MAX], Order, Temp;

void go(int node) {
    Visited[node] = Order++;

    if (!Visited[Cards[node]])
        go(Cards[node]);
    else if (!Finished[Cards[node]])
        Temp = Visited[node] - Visited[Cards[node]] + 1;

    Finished[node] = true;
}

int solution(vector<int> cards) {

    for (int i = 0; i < cards.size(); ++i)
        Cards[i + 1] = cards[i];

    vector<int> temp;
    for (int i = 1; i <= cards.size(); ++i) {
        if (!Visited[i]) {
            go(i);
            temp.push_back(Temp);
            Temp = 0;
        }
    }

    if (temp.size() <= 1)
        return 0;

    sort(temp.begin(), temp.end(), greater<int>());

    return temp[0] * temp[1];
}