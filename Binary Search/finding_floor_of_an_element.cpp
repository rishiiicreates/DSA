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
    return 0;
}