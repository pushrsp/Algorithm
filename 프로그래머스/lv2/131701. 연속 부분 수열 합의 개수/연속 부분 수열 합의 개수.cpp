#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool DP[1000 * 1000 + 1];

int solution(vector<int> elements) {
    int answer = 0;

    for (int i = 0; i < elements.size(); ++i) {
        int prev = elements[i];
        if (!DP[prev]) {
            DP[prev] = true;
            answer += 1;
        }

        int count = 1, index = (i + 1) % elements.size();
        while (count < elements.size()) {
            prev += elements[index];
            if (!DP[prev]) {
                DP[prev] = true;
                answer += 1;
            }

            index = (index + 1) % elements.size();
            count++;
        }
    }

    cout << answer << '\n';

    return answer;
}