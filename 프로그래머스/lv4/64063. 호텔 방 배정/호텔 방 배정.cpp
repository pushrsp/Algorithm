#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

#define ll long long
#define MAX 200001

using namespace std;

unordered_map<ll, ll> Rooms;

ll GetRoom(ll n) {
    if (Rooms[n] == 0)
        return n;

    return Rooms[n] = GetRoom(Rooms[n]);
}

vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer;

    for (ll &number: room_number) {
        if (Rooms[number] == 0) {
            answer.push_back(number);
            Rooms[number] = number + 1;
        } else {
            ll next_room = GetRoom(number);
            answer.push_back(next_room);
            Rooms[next_room] = next_room + 1;
        }
    }

    return answer;
}