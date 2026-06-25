//flow -> problem statement -> how to find pivot -> code variation

//problem statement:
//input: arr[]
//task: count how many times array is rotated
//output: count of rotation
// # no of array rotated = min element index

#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<int>& arr){
    int len = arr.size();
    int left = 0;
    int right = len - 1;

    while(left <= right){
        if(arr[left] <= arr[right]) return left;

        int mid = left + (right - left)/2;
        int next = (mid+1) % len;
        int prev = (mid + len - 1) % len;

        if(arr[mid] <= arr[next] && arr[mid] <= arr[prev]) return mid;
        else if(arr[mid] >= arr[left]) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main(){
    vector<int> arr{12,15,18,2,5,6,8,11};
    cout<< solve(arr);
    return 0;
}

/*
 * Explanation:
 * This file calculates how many times a sorted array has been rotated.
 * The number of rotations is equal to the index of the minimum element in the rotated sorted array.
 * 
 * Algorithm steps:
 * 1. Initialize 'left' to 0 and 'right' to the last index.
 * 2. Loop while 'left <= right':
 *    - If 'arr[left] <= arr[right]', the current sub-array is already sorted, so 'arr[left]' is the minimum, return 'left'.
 *    - Calculate 'mid'. Check its neighbors 'next' and 'prev' using modulo arithmetic to avoid out-of-bounds errors.
 *    - If 'arr[mid]' is less than or equal to both its 'next' and 'prev' elements, it is the minimum element (the pivot), so return 'mid'.
 *    - Otherwise, decide which half to search:
 *      - If 'arr[mid] >= arr[left]', the left half is sorted, meaning the minimum must lie in the unsorted right half, so update 'left = mid + 1'.
 *      - Otherwise, the minimum must be in the left half, so update 'right = mid - 1'.
 */
