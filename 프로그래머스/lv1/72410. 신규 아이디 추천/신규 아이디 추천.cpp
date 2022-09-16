#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
 *
1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
     만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.

 */

//대문자 -> 소문자
void BtoS(string &new_id) {
    for (char &i: new_id) {
        if (65 <= i && i <= 90)
            i += 32;
    }
}

//문자 제거
void ExcludeChar(string &new_id) {
    string s = "";
    for (char i: new_id) {
        if ((97 <= i && i <= 122) || (48 <= i && i <= 57)) {
            s += i;
            continue;
        }

        if (i == 45 || i == 95 || i == 46) {
            s += i;
            continue;
        }
    }

    new_id = s;
}

//마침표 치환
void ReplaceDot(string &new_id) {
    int dotIdx = -1;
    string s = "";
    for (int i = 0; i < new_id.size(); ++i) {
        if (new_id[i] == 46) {
            if (dotIdx == -1) {
                s += new_id[i];
            } else {
                if (dotIdx + 1 != i) {
                    s += new_id[i];
                }
            }
            dotIdx = i;
        } else {
            s += new_id[i];
        }
    }

    new_id = s;
}

//마침표 제거
void RemoveDot(string &new_id) {
    if (new_id[0] == 46)
        new_id.erase(new_id.begin());

    if (new_id[new_id.size() - 1] == 46)
        new_id.erase(new_id.end() - 1);
}

//빈 문자열일 경우
void FillA(string &new_id) {
    if (new_id.empty())
        new_id += 'a';
}

//16자 이상일 경우 삭제
void EraseChar(string &new_id) {
    if (new_id.size() <= 15)
        return;

    new_id.erase(new_id.begin() + 15, new_id.end());

    if (new_id[new_id.size() - 1] == 46)
        new_id.erase(new_id.end() - 1);
}

//2자 이하일 경우 끝 문자 복사
void CopyChar(string &new_id) {
    if (new_id.size() > 2)
        return;

    char c = new_id[new_id.size() - 1];
    int start = new_id.size();
    for (int i = start; i < 3; ++i)
        new_id += c;
}

string solution(string new_id) {
    string answer = "";

    BtoS(new_id);
    ExcludeChar(new_id);
    ReplaceDot(new_id);
    RemoveDot(new_id);
    FillA(new_id);
    EraseChar(new_id);
    CopyChar(new_id);

    return new_id;
}