#include <iostream>
#include <vector>
#include <string>
#define INF 1e18
 
using namespace std;
 
typedef long long ll;
 
int tc;
int n;
 
ll num[9] = {0,0,1,7,4,2,0,8,10};
ll dp[101] = {0,0,1,7,4,2,6,8,10,};
 
 
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    for(int i=9; i<=100; i++){
        dp[i] = INF;
        for(int j=2; j<=7; j++){
            dp[i] = min(dp[i-j]*10 + num[j], dp[i]);
        }
    }
    
    cin >> tc;
    while(tc--){
        cin >> n;
        
        cout << dp[n] << " ";
        
        if(n%2==0){
            int t = n/2;
            while(t--) cout << 1;
        }
        else{
            cout << 7;
            int t = n/2-1;
            while(t--) cout << 1;
        }
        cout << endl;
    }    
}