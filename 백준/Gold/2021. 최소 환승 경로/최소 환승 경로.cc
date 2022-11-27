#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int N, L, num, start, target;
vector<int> route[100001];
vector<int> station[100001];
int check[100001];
bool routeCheck[100001];

void BFS(int startX) {
	queue<int> q;
	q.push(startX);
	check[startX] = -1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (auto nextRoute : station[x]) {
			if (routeCheck[nextRoute])
				continue;
			routeCheck[nextRoute] = true;
			for (auto nextStation : route[nextRoute]) {
				if (check[nextStation] == INF) {
					check[nextStation] = check[x] + 1;
					q.push(nextStation);
				}
			}
		}
	}
	check[start] = 0; // 0으로 초기화, start와 end가 같은 경우 환승 횟수는 0이다
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> L;

	for (int i = 1; i <= L; i++) {
		while (1) {
			cin >> num;
			if (num == -1)
				break;
			route[i].push_back(num); // 루트를 지나는 역
			station[num].push_back(i); // 역에 연결된 루트 저장
		}
	}
	cin >> start >> target;

	for (int i = 1; i <= N; i++) {
		check[i] = INF;
	}

	BFS(start);

	if (check[target] == INF)
		cout << -1;
	else
		cout << check[target];
}