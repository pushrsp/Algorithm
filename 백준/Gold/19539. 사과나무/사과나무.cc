#include <bits/stdc++.h>
using namespace std;
int N, now, cnt_2, sum ;

int main()
{
    cin >> N ;
    for(int i = 0 ; i < N ; i++)
    {
        cin >> now ;
        sum += now ;
        cnt_2+= now / 2 ;
    }
    if(sum % 3 != 0) cout << "NO\n" ;
    else cnt_2 >= sum / 3 ? cout << "YES\n" : cout << "NO\n" ;
}