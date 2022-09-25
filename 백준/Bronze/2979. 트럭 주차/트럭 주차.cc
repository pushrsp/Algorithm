#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> Truck(3);
int arr[101];
int fee[4];

int main() {
    for (int i = 1; i <= 3; ++i)
        cin >> fee[i];

    int end = -1;
    for (int i = 0; i < 3; ++i) {
        int in, out;
        cin >> in >> out;

        Truck[i].first = in;
        Truck[i].second = out;

        for (int j = in; j < out; ++j)
            arr[j] += 1;

        end = max(end, out);
    }

    int answer = 0;
    for (auto &truck: Truck) {
        int price = 0;
        for (int i = truck.first; i < truck.second; ++i)
            price += fee[arr[i]];

        answer += price;
    }

    cout << answer << endl;
    return 0;
}