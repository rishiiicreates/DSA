//input: arr[infinite]
//output: index of first occurance of 1


#include <iostream>
#include <vector>
using namespace std;

long long solve(const vector<long long>& arr){
    long long left = 0;
    long long right = 1;
    long long ans = 0;

    while(left <= right){
        long long mid = left + (right - left) / 2;
        if(arr[right] < 1){
            left = right;
            right *= 2;
        }
        else if(arr[mid] == 1){
            ans = mid;
            right = mid - 1;
        }
        else if(arr[mid] > 0){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    //hypthetical question: out of bond error may appear because of unavailability of infinite arr.
    vector<long long> arr = {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};
    int result = solve(arr);
    
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the vector." << endl;
    }
}

/*
 * Explanation:
 * This file finds the index of the first occurrence of '1' in an infinitely sized binary sorted array (consisting of 0s followed by 1s).
 * 
 * Algorithm steps:
 * 1. Initially, set 'left' to 0 and 'right' to 1.
 * 2. Loop while 'left <= right':
 *    - Check if the search space bounds need to be expanded. If 'arr[right] < 1' (meaning 'arr[right]' is 0), the '1' has not been enclosed yet. Update 'left = right' and double the 'right' index ('right *= 2') to exponentially expand the search window.
 *    - Once the window contains '1', calculate 'mid'.
 *    - If 'arr[mid] == 1', store 'mid' as a potential answer in 'ans', and continue searching in the left half ('right = mid - 1') to find an earlier occurrence of 1.
 *    - If 'arr[mid] > 0' (which means it's 1), also move 'right = mid - 1'.
 *    - If 'arr[mid] == 0' (handled by the else block), the first 1 must be to the right, so update 'left = mid + 1'.
 * 3. Return 'ans'.
 */
