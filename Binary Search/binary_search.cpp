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
}

/*
 * Explanation:
 * This file implements the standard binary search algorithm to find the index of a given element 'k' in a sorted array.
 * 
 * Algorithm steps:
 * 1. Initialize 'start' to 0 and 'end' to the array's last index.
 * 2. Loop while 'start <= end':
 *    - Calculate 'mid' to avoid integer overflow.
 *    - If 'arr[mid] == k', the target is found, return 'mid'.
 *    - If 'k < arr[mid]', the element must be in the left half, so update 'end = mid - 1'.
 *    - If 'k > arr[mid]', the element must be in the right half, so update 'start = mid + 1'.
 * 3. Return -1 if the element is not found.
 */