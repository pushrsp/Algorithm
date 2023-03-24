#include <iostream>
#include <algorithm>
using namespace std;

int num[1000]; 

int main() {
	int N;          // 수의 개수
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
    
    	// 입력받은 수를 정렬
	sort(num, num + N);

	for (int i = 0; i < N; i++) {
		cout << num[i] << "\n";
	}

	return 0;
}