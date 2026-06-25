//input: arr[] -> sorted array but in decending order
//output: index of element
 
#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<int>& arr, int k){
    int len = arr.size();
    int left = 0;
    int right = len-1;

    while(left<=right){
        int mid = left + (right - left)/2;

        if(k == arr[mid]) return mid;
        else if( k < arr[mid]) left = mid + 1 ;
        else right = mid - 1;
    }
    return -1;
}

int main(){
    vector<int> arr{7,6,5,4,3,2,1};
    int k = 7;
    cout<< solve(arr, k);
    return 0;
}

/*
 * Explanation:
 * This file implements binary search on an array sorted in descending (reverse) order.
 * 
 * Algorithm steps:
 * 1. Initialize 'left' to 0 and 'right' to the last index.
 * 2. Loop while 'left <= right':
 *    - Calculate 'mid'.
 *    - If 'arr[mid] == k', the element is found, return 'mid'.
 *    - Since the array is descending:
 *      - If 'k < arr[mid]', the element 'k' must lie in the right half (where elements are smaller), so update 'left = mid + 1'.
 *      - If 'k > arr[mid]', the element 'k' must lie in the left half (where elements are larger), so update 'right = mid - 1'.
 * 3. Return -1 if the element is not found.
 */
