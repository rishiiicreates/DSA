//flow -> problem statement -> how to find pivot -> code variation

//problem statement:
//input: arr[]
//task: count how many times array is rotated
//output: count of rotation
// # no of array rotated = min element index

#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<int>& arr){
    int len = arr.size();
    int left = 0;
    int right = len - 1;

    while(left <= right){
        if(arr[left] <= arr[right]) return left;

        int mid = left + (right - left)/2;
        int next = (mid+1) % len;
        int prev = (mid + len - 1) % len;

        if(arr[mid] <= arr[next] && arr[mid] <= arr[prev]) return mid;
        else if(arr[mid] >= arr[left]) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main(){
    vector<int> arr{12,15,18,2,5,6,8,11};
    cout<< solve(arr);
    return 0;
}
