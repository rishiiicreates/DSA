//problem statement: 
//input: arr[], int element
//output: index of element

#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<int>& arr, int k){
    int len = arr.size();
    int start = 0;
    int end = len-1;

    while(start<= end){
        int mid = start + (end - start) / 2;
        if(k == arr[mid]){
            return mid;
        }else if(k < arr[mid]){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr{1,2,3,4,5,6,7,8};
    int k = 5;
    cout << solve(arr, k);
    return 0;
}