// A bitonic array (often misspelled as bionic) is a special data structure where the elements are strictly 
//increasing up to a certain peak point, and then strictly decreasing after that point.
//same as peak element.

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
}

/*
 * Explanation:
 * This file searches for an element in what is supposed to be a bitonic array.
 * Note: The binary search logic implemented here simply checks if arr[left] < arr[mid] to decide which half to search, which may not be completely standard for a bitonic array, but this is how it is implemented in this file.
 * 
 * Algorithm steps:
 * 1. Initialize 'left' to 0 and 'right' to the last index.
 * 2. Loop while 'left <= right':
 *    - Calculate 'mid'.
 *    - If 'arr[mid] == k', return 'mid'.
 *    - If 'arr[left] < arr[mid]', update 'left = mid + 1'.
 *    - Else, update 'right = mid - 1'.
 */