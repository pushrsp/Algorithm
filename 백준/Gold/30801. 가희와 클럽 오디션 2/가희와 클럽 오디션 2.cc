#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct Cmd {
    string dir;
    bool is_reverse;
    int idx;
};

map<string, int> DirToIdx;

/**
 * 방향 설정
 * ex) '!'일 시, 좌상 -> 우하, 1 -> 5 (idx + 4) % 8
 */
void set_dir() {
    DirToIdx.insert(make_pair("W", 0)); //상
    DirToIdx.insert(make_pair("8", 0)); //상
    DirToIdx.insert(make_pair("LU", 1)); //좌상
    DirToIdx.insert(make_pair("7", 1)); //좌상
    DirToIdx.insert(make_pair("A", 2)); //좌
    DirToIdx.insert(make_pair("4", 2)); //좌
    DirToIdx.insert(make_pair("LD", 3)); //좌하
    DirToIdx.insert(make_pair("1", 3)); //좌하
    DirToIdx.insert(make_pair("S", 4)); //하
    DirToIdx.insert(make_pair("2", 4)); //하
    DirToIdx.insert(make_pair("RD", 5)); //우하
    DirToIdx.insert(make_pair("3", 5)); //우하
    DirToIdx.insert(make_pair("D", 6)); //우
    DirToIdx.insert(make_pair("6", 6)); //우
    DirToIdx.insert(make_pair("RU", 7)); //우상
    DirToIdx.insert(make_pair("9", 7)); //우상
}

//문자열 파싱
vector<Cmd> get_cmd(string &str) {
    vector<Cmd> ret;

    string temp;
    for (int i = 0; i < str.length() - 1; ++i) {
        temp.push_back(str[i]);

        if (DirToIdx.find(temp) != DirToIdx.end()) {
            bool is_reverse = false;
            if (str[i + 1] == '!') {
                is_reverse = true;
                i++;
            }

            ret.push_back({temp, is_reverse});
            temp.clear();
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string str1;
    cin >> str1;

    set_dir();

    string str2;
    cin >> str2;

    //끝내는 문자
    str1.push_back('@');
    str2.push_back('@');

    vector<Cmd> cmd = get_cmd(str1);
    vector<Cmd> input = get_cmd(str2);

    //input이 작으면 애초에 키 노트를 다 누를 수 없음
    if (input.size() < cmd.size()) {
        cout << "No" << '\n';
        return 0;
    }

    for (auto &c: cmd) {
        c.idx = DirToIdx[c.dir];
        if (c.is_reverse) {
            c.idx += 4;
            c.idx %= 8;
        }
    }

    int match = 0;
    for (int i = 0; i < input.size(); ++i) {
        int in = DirToIdx[input[i].dir];
        if (match == cmd.size() || cmd[match].idx != in) {
            match = 0;
        } else {
            match++;
        }
    }

    if (match == cmd.size())
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';

    return 0;
}