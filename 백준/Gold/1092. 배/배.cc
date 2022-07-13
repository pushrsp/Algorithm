#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int N, M;

vector<int> crane;
list<int> box;

list<int>::iterator pick_best(int c) {
    auto it = box.end();
    for (auto iter = box.begin(); iter != box.end(); iter++) {
        if (*iter > c)
            break;

        it = iter;
    }

    return it;
}

int main() {
    cin >> N;

    int checkMax = 0;
    crane = vector<int>(N);
    for (int n = 0; n < N; ++n) {
        cin >> crane[n];

        if (checkMax < crane[n])
            checkMax = crane[n];
    }

    sort(crane.begin(), crane.end());

    cin >> M;
    bool check = true;
    for (int m = 0; m < M; ++m) {
        int b;
        cin >> b;

        box.push_back(b);

        if (b > checkMax)
            check = false;
    }

    box.sort();

    /**
     * 조건1: 많은 박스 중 단 한개라도 크레인이 들 수 있는 무게보다 클 시 절대 못옮김
     */

    if (!check) {
        cout << -1 << endl;
        return 0;
    }

    int cnt = 0;
    while (!box.empty()) {
        for (int &i: crane) {
            if (i == -1)
                continue;

            if (box.empty())
                break;

            auto best = pick_best(i);
            if (best == box.end()) {
                i = -1;
            } else {
                box.erase(best);
            }
        }

        cnt++;
    }

    cout << cnt << endl;

    return 0;
}