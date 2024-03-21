#include <cstring>
#include <vector>
#include <map>
#include <iostream>
#include <set>
#include <algorithm>

#define ll long long
#define INF 1e9

using namespace std;

int N;
map<char, int> Rank;

struct Char {
public:
    bool is_numeric;
    int rank, zero;
    string s;

    Char(char &c) {
        is_numeric = false;
        s.push_back(c);
        rank = Rank[c];
        zero = 0;
    }

    Char(string &ss) {
        is_numeric = true;
        rank = 0;
        int i = 0;
        for (; i < ss.length(); i++) {
            if (ss[i] != '0')
                break;
        }

        s = ss.substr(i);
        zero = ss.length() - s.length();
        if (s.empty())
            s = "0";
    }
};

struct String {
public:
    vector<Char> v;
    int size = 0;
    string origin;

    String(string &s) {
        origin = s;
        string num;
        for (int i = 0; i < s.length(); ++i) {
            if ('0' <= s[i] && s[i] <= '9') {
                num.push_back(s[i]);
            } else {
                if (!num.empty()) {
                    v.emplace_back(num);
                    num.clear();
                }

                v.emplace_back(s[i]);
            }
        }

        if (!num.empty())
            v.emplace_back(num);

        size = static_cast<int>(v.size());
    }
};

bool asc(const String &a, const String &b) {
    for (int i = 0, j = 0; i < a.size && j < b.size; ++i, j++) {
        Char c1 = a.v[i], c2 = b.v[i];
        bool n1 = c1.is_numeric, n2 = c2.is_numeric;
        if (n1 && n2) {
            // 둘다 숫자일 경우
            if (c1.s.length() != c2.s.length()) {
                return c1.s.length() < c2.s.length();
            } else {
                if (c1.s == c2.s) {
                    if (c1.zero < c2.zero)
                        return true;
                    else if (c1.zero > c2.zero)
                        return false;
                } else {
                    for (int k = 0; k < c1.s.length(); ++k) {
                        if (c1.s[k] < c2.s[k])
                            return true;
                        else if (c1.s[k] > c2.s[k])
                            return false;
                    }
                }
            }
        } else if (n1 && !n2) {
            // a만 숫자일 경우
            return true;
        } else if (!n1 && n2) {
            // b만 숫자일 경우
            return false;
        } else {
            // 둘다 숫자가 아닐 경우
            if (c1.rank < c2.rank)
                return true;
            else if (c1.rank > c2.rank)
                return false;
        }
    }

    return a.size < b.size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int rank = 1;
    for (int i = 65; i <= 90; ++i) {
        Rank[(char) i] = rank++;
        Rank[(char) (i + 32)] = rank++;
    }

    cin >> N;

    string s;
    vector<String> v;
    for (int n = 0; n < N; ++n) {
        cin >> s;
        v.emplace_back(s);
    }

    sort(v.begin(), v.end(), asc);

    for (auto &ss: v)
        cout << ss.origin << '\n';

    return 0;
}