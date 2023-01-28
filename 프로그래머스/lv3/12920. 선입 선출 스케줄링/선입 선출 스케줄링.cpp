#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> cores) {
    int answer = 0;

    if (n <= cores.size())
        return n - cores.size();

    n -= static_cast<int>(cores.size());
    int left = 1, right = 0, mid;
    for (int &core: cores)
        right = max(right, core);

    right *= n;

    int cap = 0;
    while (left < right) {
        mid = (left + right) / 2;
        for (int &core: cores)
            cap += mid / core;

        if (cap >= n)
            right = mid;
        else
            left = mid + 1;

        cap = 0;
    }

    for (int &core: cores)
        n -= (right - 1) / core;

    for (int i = 0; i < cores.size(); ++i) {
        if (right % cores[i] == 0) {
            n -= 1;

            if (n == 0)
                return i + 1;
        }
    }
    return answer;
}