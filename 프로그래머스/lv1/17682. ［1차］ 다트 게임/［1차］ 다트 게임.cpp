#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <math.h>

using namespace std;

int GetNum(deque<char> &dq) {
    string ret;
    while (!dq.empty()) {
        if ('0' <= dq.front() && dq.front() <= '9') {
            ret += dq.front();
            dq.pop_front();
            continue;
        }

        break;
    }

    return stoi(ret);
}

string GetOper(deque<char> &dq) {
    string ret = "";
    while (!dq.empty()) {
        if ('0' <= dq.front() && dq.front() <= '9')
            break;

        ret += dq.front();
        dq.pop_front();
    }

    return ret;
}

void OperStar(vector<int> &score) {
    if (score.size() == 1) {
        score[score.size() - 1] *= 2;
    } else {
        int start = score.size() - 1;
        int end = score.size() - 2;

        for (int i = start; i >= end; --i)
            score[i] *= 2;
    }
}

/**
 * 스타: 해당 점수와 바로 전에 얻은 점수를 2배
 * 아차: 해당 점수 마이너스
 */
int solution(string dartResult) {
    int answer = 0;
    deque<char> dq;
    vector<int> score;

    for (char c: dartResult)
        dq.push_back(c);

    while (!dq.empty()) {
        int num = GetNum(dq);
        string oper = GetOper(dq);

        for (char &o: oper) {
            switch (o) {
                case 'S':
                    score.push_back(static_cast<int>(pow(num, 1)));
                    break;
                case 'D':
                    score.push_back(static_cast<int>(pow(num, 2)));
                    break;
                case 'T':
                    score.push_back(static_cast<int>(pow(num, 3)));
                    break;
                case '*':
                    OperStar(score);
                    break;
                case '#':
                    score[score.size() - 1] *= -1;
                    break;
                default:
                    break;
            }
        }
    }

    for (auto &s: score)
        answer += s;
    
    return answer;
}