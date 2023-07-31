#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int STICK[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                for (int l = 0; l < 10; ++l) {
                    for (int m = 0; m < 10; ++m) {
                        for (int n = 0; n < 10; ++n) {
                            if (STICK[i] + STICK[j] + STICK[k] + STICK[l] + STICK[m] + STICK[n] + 2 + 2 == N) {
                                string t1 = to_string(i) + to_string(j);
                                string t2 = to_string(k) + to_string(l);
                                string t3 = to_string(m) + to_string(n);

                                int n1 = stoi(t1);
                                int n2 = stoi(t2);
                                int n3 = stoi(t3);

                                if (n1 + n2 == n3) {
                                    cout << t1 << '+' << t2 << '=' << t3 << '\n';
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "impossible" << '\n';

    return 0;
}