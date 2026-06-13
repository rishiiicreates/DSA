//input: arr[int], int element
//output: index

#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<int>& arr, const int& k){
    int len = arr.size();
    int left = 0;
    int right = len - 1;

    while(left <= right){
        int mid = left + (right - left) / 2;

        if(arr[mid] == k) return mid;
        else if(arr[left] < arr[mid]) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main(){
    vector<int> arr{1,3,5,8,4,2,1};
    int key = 4;
    cout<<solve(arr,key);
    return 0;
}