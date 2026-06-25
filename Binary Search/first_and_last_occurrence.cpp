//input: arr[], int k
//output: first and last occurrence of k index

#include <iostream>
#include <vector>
using namespace std;


int first_occur(const vector<int>& arr, int k){
    int len = arr.size();
    int left = 0;
    int right = len -1;
    int result = -1;

    while(left <= right){
        int mid = left + (right - left) /2 ;
        if(k == arr[mid]){
            result = mid;
            right = mid - 1;
        }
        else if(k < arr[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return result;
}

int last_occur(const vector<int>& arr, int k){
    int len = arr.size();
    int left = 0;
    int right = len -1;
    int result = -1;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(k == arr[mid]){
            result = mid;
            left = mid + 1;
        }
        else if(k < arr[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return result;
}



int main(){
    vector<int> arr{2,4,10,10,10,18,20};
    int k = 10;
    cout<< first_occur(arr,k) << "\n" << last_occur(arr, k);
}

/*
 * Explanation:
 * This file finds the first and last occurrences of a given element 'k' in a sorted array containing duplicates.
 * 
 * Algorithm steps:
 * 1. It uses two separate binary search functions: 'first_occur' and 'last_occur'.
 * 2. For 'first_occur':
 *    - Perform binary search. If 'arr[mid] == k', a match is found. Record 'mid' as a potential result and continue searching the left half ('right = mid - 1') to find any earlier occurrences.
 *    - If 'arr[mid] < k', search the right half.
 *    - If 'arr[mid] > k', search the left half.
 * 3. For 'last_occur':
 *    - Perform binary search. If 'arr[mid] == k', record 'mid' and continue searching the right half ('left = mid + 1') to find any later occurrences.
 *    - If 'arr[mid] < k', search the right half.
 *    - If 'arr[mid] > k', search the left half.
 * 4. Print both occurrences.
 */