//input: arr[], int k
//output: first and last occurrence of k index

#include <iostream>
#include <vector>
using namespace std;


int first_occur(const vector<int>& arr, int k){
    int len = arr.size();
    int left = 0;
    int right = len -1;
    int result = -1;

    while(left <= right){
        int mid = left + (right - left) /2 ;
        if(k == arr[mid]){
            result = mid;
            right = mid - 1;
        }
        else if(k < arr[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return result;
}

int last_occur(const vector<int>& arr, int k){
    int len = arr.size();
    int left = 0;
    int right = len -1;
    int result = -1;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(k == arr[mid]){
            result = mid;
            left = mid + 1;
        }
        else if(k < arr[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return result;
}



int main(){
    vector<int> arr{2,4,10,10,10,18,20};
    int k = 10;
    cout<< first_occur(arr,k) << "\n" << last_occur(arr, k);
    return 0;
}