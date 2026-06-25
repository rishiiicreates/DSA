//input: arr[] , int k;
//output: count of k in arr;

#include <iostream>
#include <vector>
using namespace std;

int first_occur(const vector<int>& arr,const int& k){
    int len = arr.size();
    int left = 0;
    int right = len - 1;
    int result = -1;

    while(left <= right){
        int mid = left + (right - left)/2;
        if (k == arr[mid]){
            result = mid;
            right = mid - 1;
        }else if(k < arr[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return result;
}

int last_occur(const vector<int>& arr,const int& k){
    int len = arr.size();
    int left = 0;
    int right = len - 1;
    int result = -1;

    while( left <= right){
        int mid = left + (right - left)/2;
        if(k == arr[mid]){
            result = mid;
            left = mid + 1;
        }else if( k < arr[mid]) right = mid - 1;
        else left = mid + 1;
    }

    return result;
}

int count(const vector<int>& arr,const int& k){
    int ans = (last_occur(arr,k) - first_occur(arr,k)) + 1;
    return ans;
}

int main(){
    vector<int> arr{2,4,10,10,10,18,20};
    int k = 10;
    cout<<count(arr,k);
}

/*
 * Explanation:
 * This file counts the number of occurrences of an element 'k' in a sorted array.
 * 
 * Algorithm steps:
 * 1. It uses two binary search helper functions: 'first_occur' to find the first index of 'k' and 'last_occur' to find the last index.
 * 2. 'first_occur' performs standard binary search, but when 'arr[mid] == k' is met, it updates 'right = mid - 1' to find earlier occurrences.
 * 3. 'last_occur' performs standard binary search, but when 'arr[mid] == k' is met, it updates 'left = mid + 1' to find later occurrences.
 * 4. The total count is calculated as '(last_occur - first_occur) + 1'.
 */