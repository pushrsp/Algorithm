#include <iostream>

using namespace std;

int main()
{
    int num1;
    cin >> num1;
    
    char num2; 

    int sum = 0;

    for(int i=0; i<num1; i++)
    {
        cin >> num2;
        sum += (num2 - '0');
    }

    cout<<sum<<endl;

    return 0;
}