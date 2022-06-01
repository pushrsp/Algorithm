#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

bool isPrime[1004000];
int N;

void erathos() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;

    for (int i = 2; i * i < 1004000; i++) {
        if (!isPrime[i])
            continue;
        
        for (int j = i + i; j < 1004000; j += i) {
            isPrime[j] = false;
        }
    }
}

bool isPalin(int n) {
    string str = to_string(n);

    for (int i = 0; i < str.length() / 2; i++) {
        if (str[i] != str[str.length() - 1 - i])
            return false;
    }

    return true;
}

int main() {
    cin >> N;

    erathos();

    for (int i = N;; i++) {
        if (!isPrime[i])
            continue;

        if (isPalin(i)) {
            cout << i;
            break;
        }
    }
    return 0;
}