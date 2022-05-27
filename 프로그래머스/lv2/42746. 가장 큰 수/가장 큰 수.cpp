#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string &a, const string &b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> result;
    string answer = "";

    for (int i = 0; i < numbers.size(); ++i)
        result.push_back(to_string(numbers[i]));

    sort(result.begin(), result.end(), cmp);

    for (int i = 0; i < result.size(); ++i)
        answer += result[i];

    if (answer[0] == '0')
        return "0";

    return answer;
}