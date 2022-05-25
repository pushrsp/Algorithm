#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> q_progress;
    queue<int> q_speed;

    for (auto p: progresses)
        q_progress.push(p);

    for (auto s: speeds)
        q_speed.push(s);

    int complete = 0;

    while (!q_progress.empty()) {
        for (int i = 0; i < q_progress.size(); ++i) {
            int p_temp = q_progress.front();
            int s_temp = q_speed.front();

            q_progress.pop();
            q_speed.pop();

            p_temp += s_temp;

            q_progress.push(p_temp);
            q_speed.push(s_temp);
        }

        if (!q_progress.empty()) {
            while (q_progress.front() >= 100) {
                q_progress.pop();
                q_speed.pop();
                complete++;

                if (q_progress.empty())
                    break;
            }
        }

        if (complete > 0) {
            answer.push_back(complete);
            complete = 0;
        }
    }

    return answer;
}