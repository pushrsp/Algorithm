#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long

struct Room {
    ll t, a, h;
};

vector<Room> Rooms;
ll N, ATK;

bool is_valid(ll maxHp) {
    ll curHp = maxHp, curAtk = ATK;

    for (auto room: Rooms) {
        if (room.t == 1) {
            ll atk_cnt = room.h / curAtk;
            if (room.h % curAtk != 0)
                atk_cnt++;

            curHp -= (atk_cnt - 1) * room.a;
            if (curHp <= 0)
                return false;
        } else {
            curHp += room.h;
            curAtk += room.a;
            if (curHp > maxHp)
                curHp = maxHp;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> ATK;

    Rooms = vector<Room>(N);
    for (int n = 0; n < N; ++n)
        cin >> Rooms[n].t >> Rooms[n].a >> Rooms[n].h;

    ll left = 1, right = INT64_MAX, mid, ret = INT64_MAX;
    while (left <= right) {
        mid = (left + right) / 2;

        if (is_valid(mid)) {
            ret = min(ret, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ret << '\n';
    return 0;
}