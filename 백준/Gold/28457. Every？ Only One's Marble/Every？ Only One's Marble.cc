#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;

int N, S, W, G, I;
vector<pair<int, int>> Board, Special;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> S >> W >> G;

    int a, b;
    for (int g = 0; g < G; ++g) {
        cin >> a >> b;
        Special.emplace_back(a, b);
    }

    int len = (4 * N) - 4;
    Board = vector<pair<int, int>>(len);

    Board[0].first = -1;
    Board[N - 1].first = -2;
    Board[((2 * N) - 1) - 1].first = -3;
    Board[((3 * N) - 2) - 1].first = -4;

    int start = 1, city = 0;
    char c;
    for (int n = 0; n < len - 4; ++n) {
        cin >> c;

        if (c == 'G') {
            Board[start].first = 1;
        } else {
            cin >> b;

            Board[start].first = 0;
            Board[start].second = b;
            city += 1;
        }

        start++;

        if (Board[start].first < 0)
            start++;
    }

    cin >> I;

    bool success = true, mooindo = false;
    set<int> s;
    int pos = 0, special = 0, mooindo_count = 0, donation = 0;
    for (int i = 0; i < I; ++i) {
        cin >> a >> b;

        if (mooindo) {
            mooindo_count++;

            if (a == b || mooindo_count == 3) {
                mooindo_count = 0;
                mooindo = false;
            }

            continue;
        }

        pos += a + b;
        if (pos >= len)
            S += W * (pos / len);

        pos %= len;

        if (Board[pos].first < 0) { //특별칸
            if (Board[pos].first == -2) { //무인도
                mooindo = true;
            } else if (Board[pos].first == -3) { //사회복지기금
                S += donation;
                donation = 0;
            } else if (Board[pos].first == -4) { // 우주여행
                pos = 0;
                S += W;
            }
        } else if (Board[pos].first == 1) { //황금 열쇠
            int cmd = Special[special].first;

            if (cmd == 1) { //은행에서 x원 받는다.
                S += Special[special].second;
            } else if (cmd == 2) { // 은행에 x원을 준다.
                S -= Special[special].second;
            } else if (cmd == 3) { // 사회복지기금에 x원 기부
                S -= Special[special].second;
                donation += Special[special].second;
            } else { //앞으로 y칸 이동
                pos += Special[special].second;

                if (pos >= len)
                    S += W * (pos / len);

                pos %= len;

                if (Board[pos].first < 0) {
                    if (Board[pos].first == -2) { //무인도
                        mooindo = true;
                    } else if (Board[pos].first == -3) { //사회복지기금
                        S += donation;
                        donation = 0;
                    } else if (Board[pos].first == -4) { // 우주여행
                        pos = 0;
                        S += W;
                    }
                } else if (Board[pos].first == 0) {
                    if (S >= Board[pos].second && s.find(pos) == s.end()) { // 충분한 돈을 갖고있으면서 해당 땅을 아직 사지 않을 경우
                        s.insert(pos);
                        S -= Board[pos].second;
                    }
                }
            }

            if (S < 0)
                success = false;

            special = (special + 1) % G;
        } else { //땅 구매
            if (S >= Board[pos].second && s.find(pos) == s.end()) { // 충분한 돈을 갖고있으면서 해당 땅을 아직 사지 않을 경우
                s.insert(pos);
                S -= Board[pos].second;
            }
        }
    }

    if (!success) {
        cout << "LOSE" << '\n';
        return 0;
    }

    if (s.size() != city) {
        cout << "LOSE" << '\n';
        return 0;
    }

    cout << "WIN" << '\n';

    return 0;
}