#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct ReqJob {
    int request, duration;
    
    bool operator<(const ReqJob& other) const {
        if(request == other.request)
            return duration > other.duration;
        
        return request > other.request;
    }
};

struct DurJob {
    int request, duration;
    
    bool operator<(const DurJob& other) const {
        if(duration == other.duration)
            return request > other.request;
        
        return duration > other.duration;
    }
};



int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    priority_queue<ReqJob> req_pq;
    for(auto& job: jobs)
        req_pq.push({job[0], job[1]});
    
    int now = 0;
    priority_queue<DurJob> dur_pq;
    while(!dur_pq.empty() || !req_pq.empty()) {
        while(!req_pq.empty() && req_pq.top().request <= now) {
            dur_pq.push({req_pq.top().request, req_pq.top().duration});
            req_pq.pop();
        }
        
        if(dur_pq.empty()) {
            now = req_pq.top().request + req_pq.top().duration;
            answer += req_pq.top().duration;
            req_pq.pop();
        } else {
            if(now > dur_pq.top().request)
                answer += now - dur_pq.top().request; //대기 시간
            
            answer += dur_pq.top().duration;
            now += dur_pq.top().duration;
            dur_pq.pop();
        }
    }
    
    return answer / jobs.size();
}