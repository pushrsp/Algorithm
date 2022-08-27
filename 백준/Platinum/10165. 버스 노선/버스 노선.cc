#include <iostream>
#include <algorithm>
#include <vector>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
const int MAX = 500011;
int N, M;
vector<pair<pi, int>> v;
bool visit[MAX];
bool cmp(pair<pi, int> p1, pair<pi, int> p2) {
	if (p1.first.first == p2.first.first)
		return p1.first.second > p2.first.second;
	return p1.first.first < p2.first.first;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		if (a < b) {
			v.push_back({ {a,b}, i });
			v.push_back({{ a + N, b + N }, i});
		}
		else
			v.push_back({ { a, b + N }, i });
	}
	sort(all(v), cmp);
	int s = 0, e = 0, left = 0, right = 0;
	for (int i = 0; i < v.size(); i++) {
		s = v[i].first.first;
		e = v[i].first.second;
		int idx = v[i].second;
		if (visit[idx])
			continue;
		if (left <= s && e <= right) {
			visit[idx] = true;
			continue;
		}
		left = s;
		right = e;
	}
	for (int i = 0; i < M; i++) {
		if (!visit[i])
			cout << i + 1 << " ";
	}
}