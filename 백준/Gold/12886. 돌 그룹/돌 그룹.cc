#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int visited[1001][1001] = { 0, };
int a, b, c, d = 0;

int bfs() {

	queue <pair<int, int>> que;
	que.push(make_pair(a, b));
	visited[a][b] = 1;

	while (!que.empty()) {
		int ca = que.front().first;
		int cb = que.front().second;
		int cc = d - ca - cb;
		que.pop();

		if (ca == cb && ca == cc)
			return 1;

		int n_x[3] = { ca,ca,cb };
		int n_y[3] = { cb,cc,cc };

		for (int i = 0; i < 3; i++) {
			int na = n_x[i];
			int nb = n_y[i];
			if (na < nb)
				nb -= na, na += na;
			else if (na > nb)
				na -= nb, nb += nb;
			else
				continue;
			int nc = d - na - nb;

		
			int ra = min(min(na, nb), nc);
			int rb = max(max(na, nb), nc);

			if (visited[ra][rb] == 0) {
				visited[ra][rb] = 1;
				que.push(make_pair(ra, rb));
			}

		}


	}

	return 0;

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> a >> b >> c;
	d = a + b + c;

	if ((a + b + c) % 3 != 0)
		cout << 0 << endl;
	else
		cout << bfs() << endl;
	

	return 0;
}