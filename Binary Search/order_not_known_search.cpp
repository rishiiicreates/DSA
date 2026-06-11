//order agnostinc search

#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<int>& arr, int k){
    int len = arr.size();
    int left = 0;
    int right = len - 1;

    if(arr[left] < arr[right]){
        while(left <= right){
            int mid = left + (right-left) / 2 ;
            if(k == arr[mid]) return mid;
            else if ( k < arr[mid]) right = mid - 1;
            else left = mid + 1;
        }
    }else if(arr[left] > arr[right]){
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(k == arr[mid]) return mid;
            else if (k < arr[mid]) left = mid + 1;
            else right = mid - 1;
        }
    }
    return -1;
}


int main(){
    vector<int> arr{1,2,3,4,5,6,7};
    reverse(arr.begin(),arr.end());
    int k = 5;
    cout << solve(arr,k);
    return 0;
}