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
}

/*
 * Explanation:
 * This file implements "Order Agnostic Binary Search", which searches for an element 'k' in an array that is sorted, but it's unknown whether it's sorted in ascending or descending order.
 * 
 * Algorithm steps:
 * 1. Determine the sort order by comparing the first and last elements ('arr[left]' and 'arr[right]').
 * 2. If 'arr[left] < arr[right]', the array is sorted in ascending order. Perform standard binary search: if 'k < arr[mid]', go left ('right = mid - 1'), else go right ('left = mid + 1').
 * 3. If 'arr[left] > arr[right]', the array is sorted in descending order. Perform reverse binary search: if 'k < arr[mid]', go right ('left = mid + 1'), else go left ('right = mid - 1').
 * 4. If 'k' is found at 'arr[mid]', return 'mid'. Otherwise, return '-1'.
 */