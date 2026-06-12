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
    return 0;
}