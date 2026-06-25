//input: arr[] , int element
//problem statement:
//floor: element = 7.8 ; floor -> 7 and ceil -> 8;
//here, floor: if element present in arr then floor = ceil = element;
//             else greatest element smaller then 5;
//output: floor element

#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<int>& arr,const int& k){
    int len = arr.size();
    int left = 0;
    int right = len - 1;

    int ans = 0;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(k == arr[mid]) return arr[mid];
        else if(arr[mid] < k){
            ans = arr[mid];
            left = mid + 1;
        }else if(arr[mid] > k){
            right = mid - 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr{1,2,3,4,8,10,12,19};
    int k = 5;
    cout<<solve(arr,k);
}

/*
 * Explanation:
 * This file implements binary search to find the "floor" of a given element 'k' in a sorted array.
 * The floor of 'k' is the greatest element in the array that is less than or equal to 'k'.
 * 
 * Algorithm steps:
 * 1. Initialize 'left' to 0 and 'right' to the array's last index.
 * 2. Use a variable 'ans' to track the floor value.
 * 3. Loop while 'left <= right':
 *    - Calculate 'mid'.
 *    - If 'arr[mid] == k', 'k' itself is the floor, so return 'arr[mid]'.
 *    - If 'arr[mid] < k', 'arr[mid]' is a candidate for the floor. Store it in 'ans' and search the right half ('left = mid + 1') for a potentially larger candidate that is still less than or equal to 'k'.
 *    - If 'arr[mid] > k', the floor must lie in the left half, so update 'right = mid - 1'.
 * 4. Return 'ans'.
 */