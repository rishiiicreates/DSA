//input: arr[] -> sorted array but in decending order
//output: index of element
 
#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<int>& arr, int k){
    int len = arr.size();
    int left = 0;
    int right = len-1;

    while(left<=right){
        int mid = left + (right - left)/2;

        if(k == arr[mid]) return mid;
        else if( k < arr[mid]) left = mid + 1 ;
        else right = mid - 1;
    }
    return -1;
}

int main(){
    vector<int> arr{7,6,5,4,3,2,1};
    int k = 7;
    cout<< solve(arr, k);
    return 0;
}
