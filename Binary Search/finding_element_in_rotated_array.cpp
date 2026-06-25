
#include <iostream>
#include <vector>
using namespace std;


int Bsearch(const vector<int>& arr, int left, int right, int k){
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(k == arr[mid]) return mid;
        else if(k < arr[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int rotation(const vector<int>& arr, const int& k){
    int len = arr.size();
    int left = 0;
    int right = len - 1;
    int pivot = -1;


    if (arr[left] <= arr[right]) {
        return Bsearch(arr, 0, len - 1, k);
    }

    while(left <= right){
        int mid = left + (right - left) / 2;
        int next = (mid + 1) % len;
        int prev = (mid + len - 1) % len;

        if(arr[mid] >= arr[next] && arr[mid] >= arr[prev]){
            pivot = mid;
            break;
        }
        else if(arr[mid] >= arr[left]) left = mid + 1;
        else right = mid - 1;
    }

    int ans = Bsearch(arr, 0, pivot, k);
    if(ans != -1) return ans;
    
    return Bsearch(arr, pivot + 1, len - 1, k);
}

int main(){
    vector<int> arr{11,12,15,18,2,5,6,8};
    int k = 5;
    cout << rotation(arr, k); // Outputs: 5
}

/*
 * Explanation:
 * This file searches for an element in a rotated sorted array.
 * 
 * Algorithm steps:
 * 1. The algorithm finds the pivot (minimum element) first to know the rotation point.
 * 2. First, check if the array is already perfectly sorted ('arr[left] <= arr[right]'). If so, simply perform standard binary search.
 * 3. If rotated, use binary search to find the pivot index (the minimum element). Loop while 'left <= right':
 *    - Calculate 'mid' and find 'next' and 'prev' using modulo arithmetic to prevent out-of-bounds.
 *    - If 'arr[mid]' is smaller than or equal to both 'next' and 'prev', it is the pivot.
 *    - Else, if the left half is sorted ('arr[mid] >= arr[left]'), the pivot must be in the unsorted right half ('left = mid + 1').
 *    - Else, the right half is sorted, meaning the pivot must be in the left half ('right = mid - 1').
 * 4. Once the pivot is found, the array is divided into two sorted sub-arrays. First, binary search the left sub-array from index 0 to 'pivot'. If the element is found, return its index.
 * 5. If not found, binary search the right sub-array from 'pivot + 1' to the end.
 */