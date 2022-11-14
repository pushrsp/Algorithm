#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <bitset>

#define ll long long

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < arr1.size(); ++i) {
        string bin = bitset<32>(arr1[i] | arr2[i]).to_string();
        string temp;

        for (int j = 32 - n; j < 32; ++j) {
            if (bin[j] == '0')
                temp += ' ';
            else
                temp += '#';
        }

        answer.push_back(temp);
    }

    return answer;
}