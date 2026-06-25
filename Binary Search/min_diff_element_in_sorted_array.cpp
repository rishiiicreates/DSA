//input: arr[int], int element
//output: element - arr[element] = min difference;
//basically min(floor,ceil) of element 

#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<int>& arr,const int& k){
    int len = arr.size();
    int left = 0;
    int right = len-1;

    while(left <= right){
        int mid = left + (right - left) / 2;

        if(arr[mid] == k) return arr[mid];
        else if(arr[mid] > k) right = mid - 1;
        else left = mid + 1; 
    }
    return abs(arr[left] - k) < abs(arr[right] - k) ? arr[left] : arr[right];
}


int main(){
    vector<int> arr{1,2,3,4,8,12,19};
    int k = 11;
    cout<< "Element:" << abs(solve(arr,k)) << "  Difference:" << k - abs(solve(arr,k)) << endl;
}

/*
 * Explanation:
 * This file finds the element in a sorted array that has the minimum absolute difference with a given target value 'k'.
 * 
 * Algorithm steps:
 * 1. Perform standard binary search to find 'k'. Initialize 'left = 0' and 'right = len - 1'. Loop while 'left <= right'.
 * 2. If 'arr[mid] == k', the difference is 0, so return 'arr[mid]'.
 * 3. If 'k < arr[mid]', search left ('right = mid - 1'). If 'k > arr[mid]', search right ('left = mid + 1').
 * 4. If the loop finishes without finding 'k', 'left' and 'right' will cross. At this point, 'arr[left]' and 'arr[right]' are the two closest elements to 'k' (they represent the ceil and floor of 'k', respectively).
 * 5. Compare the absolute differences 'abs(arr[left] - k)' and 'abs(arr[right] - k)' and return the element that produces the smaller difference.
 */