#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<int>& arr,const int& k){
    int len = arr.size();
    int left = 0;
    int right = len -1;

    int ans = 0;
    
    while(left <= right){
        int mid = left + (right - left) / 2;

        if(arr[mid] == k) return arr[mid];
        else if(k > arr[mid]){
            left = mid + 1;
        }else if(k < arr[mid]){
            right = mid - 1;
            ans = arr[mid];
        }
    }
    return ans;
}


int main(){
    vector<int> arr{1,2,3,4,8,10,12,19};
    int k = 5;
    cout<<solve(arr,k);
    return 0;
}