#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,n) for(int i=1;i<=n;++i)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
using namespace std;

string S;
int s;
int cache[26][1001];
int lo[27],hi[27];
bool exist[26];
int dist(int a, int b, int c,int d) {
    if (c == -1 || d == -1) return 0;
    
    int A = abs(a - c);
    int B = abs(c - d);
    int C = abs(d - b);
    return A + B + C;	
}

int solve(int alpha, int pos) {
    if (alpha==26) return 0;
    int& ret = cache[alpha][pos];
    if (ret != -1) return ret;
    ret = INT_MAX/2;
    int posl = lo[alpha];
    int posr = hi[alpha];
    
    if (exist[alpha]) 
        rep(i, s)
            ret = min(ret, solve(alpha + 1, i) + min(dist(pos, i, posl, posr), dist(pos, i, posr, posl)));
    else ret =solve(alpha + 1, pos);
    
    return ret;
}

int main() {
    FAST;
    cin >> S;
    s = S.size();
    memset(cache, -1, sizeof(cache));
    memset(lo, 0x3f, sizeof(lo));
    memset(hi, -1, sizeof(hi));

    rep(i, 26) rep(j, s) {
        if (S[j] - 'a' == i) {
            exist[i] = 1;
            lo[i] = min(lo[i], j);	
            hi[i] = max(hi[i], j);
        }
    }
    
    int ret = solve(0, 0);
    cout << ret + s;

    return 0;
}