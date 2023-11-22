#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int>&arr,int target, int start, int end) {
    while(start <= end) {
        int mid = (start + end) /2;

        if(arr[mid]==target)
            return mid;
        else if (arr[mid]>target)
            end = mid-1;
        else
            start = mid+1;
    }
    return -1;
}

int n,m;
vector<int> arr;
vector<int> s;

int main() {
    cin >> n;

    for (auto i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());

    cin >> m;

    for (auto i =0; i< m; i++) {
        int x;
        cin >> x;
        s.push_back(x);
    }
    
    for(auto i =0; i<m;i++) {
        int result = binarySearch(arr,s[i],0,n-1);

        if(result!=-1) {
            cout << "1 ";
        }else cout << "0 ";
    }
}