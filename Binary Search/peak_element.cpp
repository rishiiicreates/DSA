// #not sorted array!
//flow: problem statement -> criteria -> mid ans or not -> left/right criteria -> code variation

//input: arr[not sorter]
//output: index of peak element
//        peak element: element which is greater then both of the neighbor


//identification:


#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<int>& arr){
    int len = arr.size();
    if (len == 1) return 0; // Quick exit for single-element arrays
    
    int left = 0;
    int right = len - 1;

    while(left <= right){
        int mid = left + (right - left)/2;

        if((mid == 0 || arr[mid] > arr[mid - 1]) && (mid == len - 1 || arr[mid] > arr[mid + 1])){
            return mid;
        }
        if(mid > 0 && arr[mid - 1] > arr[mid]){
            right = mid - 1;
        } 
        else {
            left = mid + 1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr{10,20,15,2,23,90,67};
    //answer should be any one of peak element: either 20 or 90
    int ans = solve(arr);
    cout << arr[ans];
    return 0;
}
