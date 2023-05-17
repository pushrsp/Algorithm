#include <iostream>
#include <algorithm>

using namespace std;

int L, K, C;
int ks[10001];

int check(int tgt) {

    int temp = 0;
    int from = L;
    int cut = C;
    // 오른쪽부터 탐색
    for(int i = K-1; i>=0 && cut>0; i--) { 
        if(from-ks[i] > tgt) {  // 나무조각이 목표길이보다 커지면 직전 지점에서 자름
            if(ks[i+1]-ks[i] > tgt) {  // 목표길이보다 작게 자를수 없는 조각 발견시 -1 반환
                return -1;
            }
            cut--;
            from = ks[i+1];
        }
    }

    if(cut > 0) {
        from = ks[0];  // 아직 자를 수 있다면 가장 왼쪽에서 자름
    }

    if(from > tgt) {
        return -1;  // 남은 조각이 목표길이보다 크면 -1 반환
    }
    else {
        return from; // 그렇지 않으면 자른 위치중 가장 왼쪽값 반환
    }
}

int main() {

    cin >> L >> K >> C;
    for(int i = 0; i < K; i++) {
        cin >> ks[i];
    }

    sort(ks, ks+K);  //자르는 위치 정렬
    ks[K] = -1;
    int j = 0;
    for(int i = 0; i < K; i++) {  // 자르는 위치 중복값 제거
        ks[j] = ks[i];
        if(ks[i] != ks[i+1]) {
            j++;
        }
    }
    K = j;
    ks[K] = L;

    int start = L/(C+1);
    int end = L;
    int mid, ret;
    while(start<end) {  // L/(C+1)부터L까지 이분탐색
        mid = (start+end)/2;
        ret = check(mid);
        if(ret >= 1) {
            end = mid;
        }
        else{
            start = mid+1;
        }
    }
    
    cout << start << ' ' << check(start) << endl;
    
    return 0;
}