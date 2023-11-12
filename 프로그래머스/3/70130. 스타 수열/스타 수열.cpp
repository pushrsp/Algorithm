#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    vector<int> nums(a.size() + 1);
    for (auto &num: a)
        nums[num]++;

    int answer = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0)
            continue;
        if (nums[i] <= answer)
            continue;

        int temp = 0;
        for (int j = 0; j < a.size() - 1; ++j) {
            if (a[j] != i && a[j + 1] != i)
                continue;
            if (a[j] == a[j + 1])
                continue;

            temp += 1;
            j++;
        }

        answer = max(answer, temp);
    }

    return answer * 2;
}