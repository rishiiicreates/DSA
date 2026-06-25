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

/*
 * Explanation:
 * This file implements binary search to find the "ceil" of a given element 'k' in a sorted array.
 * The ceil of 'k' is the smallest element in the array that is greater than or equal to 'k'.
 * 
 * Algorithm steps:
 * 1. Initialize 'left' to 0 and 'right' to the last index of the array.
 * 2. Use a variable 'ans' to store the potential ceil value.
 * 3. Loop while 'left <= right':
 *    - Calculate 'mid'.
 *    - If 'arr[mid] == k', then 'k' itself is the ceil, so return 'arr[mid]'.
 *    - If 'k > arr[mid]', the ceil must be to the right of 'mid', so update 'left = mid + 1'.
 *    - If 'k < arr[mid]', 'arr[mid]' is a candidate for the ceil. Store it in 'ans' and search in the left half ('right = mid - 1') to find a potentially smaller candidate that is still greater than 'k'.
 * 4. Return 'ans'.
 */