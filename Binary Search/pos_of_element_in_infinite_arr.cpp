//input: arr[infinite], int [element]
//output: element:


#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<long long>& arr, int element){
    long long left = 0;
    long long right = 1;

    while(left <= right){
        long long mid = left + (right - left) / 2;
        if(arr[right] < element){
            left = right;
            right *= 2;
        }
        else if(arr[mid] == element ){
            return mid;
        }
        else if(arr[mid] < element){
            left = mid + 1;
        }
        else if(arr[mid] > element){
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    //hypthetical question: out of bond error may appear because of unavailability of infinite arr.
    vector<long long> arr = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target = 14;
    int result = solve(arr, target);
    
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the vector." << endl;
    }
}

/*
 * Explanation:
 * This file finds the position of a specific element in an infinitely sized sorted array.
 * 
 * Algorithm steps:
 * 1. Initialize 'left' to 0 and 'right' to 1.
 * 2. Loop while 'left <= right':
 *    - Check if the search window contains the target element. If the element at 'right' is smaller than the target ('arr[right] < element'), the target must be further to the right. Therefore, update 'left = right' and double the 'right' index ('right *= 2') to exponentially expand the search space until the target is within bounds.
 *    - If the target is within the bounds, calculate 'mid'.
 *    - If 'arr[mid] == element', the target is found, return 'mid'.
 *    - If 'arr[mid] < element', search in the right half by setting 'left = mid + 1'.
 *    - If 'arr[mid] > element', search in the left half by setting 'right = mid - 1'.
 * 3. Return -1 if not found.
 */