#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

int N;

bool cmp_string(const string& a, const string& b)
{
    return a + b > b + a;
}

int main() {
    cin >> N;

    vector<string> vec(N);
    for (int n = 0; n < N; n++)
        cin >> vec[n];
    
    sort(vec.begin(), vec.end(), cmp_string);

    if (vec[0] == "0")
    {
        cout << "0" << endl;
    }
    else
    {
        for (int n = 0; n < N; n++)
            cout << vec[n];

        cout << endl;
    }
    return 0;
}