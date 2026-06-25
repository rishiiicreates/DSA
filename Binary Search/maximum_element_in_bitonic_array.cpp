// A bitonic array (often misspelled as bionic) is a special data structure where the elements are strictly 
//increasing up to a certain peak point, and then strictly decreasing after that point.
//same as peak element.

#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<int>& arr){
    int len = arr.size();
    int left = 0;
    int right = len - 1;

    while(left <= right){
        int mid = left + (right - left) / 2;

        if(((mid == 0) ||(arr[mid] > arr[mid - 1])) && ((mid == len - 1) || (arr[mid] > arr[mid+1]))) return mid;
        else if((mid < len-1) && (arr[mid] > arr[mid+1])) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int main(){
    vector<int> arr{1,3,8,12,4,2};
    cout<<arr[solve(arr)];
}

/*
 * Explanation:
 * This file finds the peak (maximum) element in a bitonic array (an array that strictly increases to a peak and then strictly decreases).
 * 
 * Algorithm steps:
 * 1. Initialize 'left' to 0 and 'right' to the last index.
 * 2. Loop while 'left <= right':
 *    - Calculate 'mid'.
 *    - Check if 'mid' is the peak: It is the peak if it's strictly greater than both its neighbors (with bounds checks for the ends of the array).
 *    - If 'arr[mid] > arr[mid+1]' (and 'mid' is not the last element), the array is decreasing at 'mid'. This means the peak must be to the left, so update 'right = mid - 1'.
 *    - Else, the array is increasing at 'mid', so the peak must be to the right, update 'left = mid + 1'.
 */