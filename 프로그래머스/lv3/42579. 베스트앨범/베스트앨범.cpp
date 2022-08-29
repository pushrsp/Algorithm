#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Music {
    string genres;
    int plays, idx;
};

unordered_map<string, int> um;
vector<Music> vec;

/**
 *
 * 1. 속한 노래가 많이 재생된 장르
 * 2. 장르 내에서 많이 재생된 노래
 * 3. 장르 내에서 재생 횟수가 같은 노래 중에서 고유번호가 낮은 노래
 */
bool cmp_music(const Music &a, const Music &b) {
    if (a.genres == b.genres) {
        if (a.plays == b.plays)
            return a.idx < b.idx;

        return a.plays > b.plays;
    }

    return um[a.genres] > um[b.genres];
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    for (int i = 0; i < plays.size(); ++i) {
        um[genres[i]] += plays[i];
        vec.push_back({genres[i], plays[i], i});
    }

    sort(vec.begin(), vec.end(), cmp_music);

    string pivot = vec[0].genres;
    answer.push_back(vec[0].idx);
    int cnt = 1;

    for (int i = 1; i < vec.size(); ++i) {
        if (pivot == vec[i].genres) {
            if (cnt < 2) {
                answer.push_back(vec[i].idx);
                cnt++;
            }
        } else {
            pivot = vec[i].genres;
            cnt = 1;
            answer.push_back(vec[i].idx);
        }
    }
    
    return answer;
}