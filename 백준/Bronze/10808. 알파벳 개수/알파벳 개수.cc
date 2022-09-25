#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int arr[26];

int main() {
    string s;
    cin >> s;

    for (char c: s)
        arr[c - 'a']++;

    for (int i: arr)
        cout << i << " ";


    return 0;
}