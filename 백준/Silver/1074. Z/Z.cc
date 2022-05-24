#include <iostream>
#include <cmath>

using namespace std;

int **arr;
int answer;

void solution(int n, int r, int c) {
    if (n < 1)
        return;

    int size = 1 << n;
    int half = size / 2;

    if (r / half == 0 && c / half == 0) { //왼쪽 위
        answer += half * half * 0;
        solution(n - 1, r % half, c % half);
    } else if (r / half == 0 && c / half == 1) { //오른쪽 위
        answer += half * half * 1;
        solution(n - 1, r % half, c % half);
    } else if (r / half == 1 && c / half == 0) { //왼쪽 아래
        answer += half * half * 2;
        solution(n - 1, r % half, c % half);
    } else if (r / half == 1 && c / half == 1) { //오른쪽 아래
        answer += half * half * 3;
        solution(n - 1, r % half, c % half);
    }
}

int main() {
    int n, r, c;
    cin >> n >> r >> c;

    arr = new int *[static_cast<int>(pow(2, n))];
    for (int i = 0; i < sizeof(arr); ++i) {
        arr[i] = new int[sizeof(arr)];
    }

    solution(n, r, c);

    cout << answer << endl;


    return 0;
}