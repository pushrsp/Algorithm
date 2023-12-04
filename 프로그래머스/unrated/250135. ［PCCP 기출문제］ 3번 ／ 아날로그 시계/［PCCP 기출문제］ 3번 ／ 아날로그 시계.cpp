#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iostream>

using namespace std;

/**
 * 시침은 초당 1 움직임
 * 분침은 초당 1/60 움직임
 * 시침은 초당 1/12 * 1/60 움직임
 *
 * 실수연산을 하지 않기 위해 아래처럼 나타낼 수 있음
 *
 * 초침은 1초당 720 만큼 갈 수 있음
 * 분침은 720/60=12 만큼 갈 수 있음
 * 시침은 720/720=1 만큼 갈 수 있음
 *
 * 총 거리는 3600 * 720 = 43200 만큼 갈 수 있음
 */

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int start = (h1 * 3600) + (m1 * 60) + s1;
    int end = (h2 * 3600) + (m2 * 60) + s2;

    int answer = 0;

    int cs = s1 * 720;
    int cm = (m1 * 60 + s1) * 12;
    int ch = (h1 % 12) * 3600 + (m1 * 60 + s1);

    //현재 초침이 시침/분침과 겹칠 때 +1
    if (cs == cm || cs == ch)
        answer += 1;

    while (start < end) {
        int ps = cs;
        int pm = cm;
        int ph = ch;

        cs += 720;
        cm += 12;
        ch += 1;

        //간 거리가 같거나 전에 초침이 분침보다 작고 현재 초침이 분침보다 클 경우 +1
        if (cs == cm || (ps < pm && cs > cm))
            answer += 1;

        //간 거리가 같거나 전에 초침이 시침보다 작고 현재 초침이 시침보다 클 경우 +1
        if (cs == ch || (ps < ph && cs > ch))
            answer += 1;

        cs %= 43200;
        cm %= 43200;
        ch %= 43200;

        start++;
    }
    
    if(h1 < 12 && h2 >= 12)
        answer--;

    return answer;
}