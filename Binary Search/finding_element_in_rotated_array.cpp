
#include <iostream>
#include <vector>
using namespace std;


int Bsearch(const vector<int>& arr, int left, int right, int k){
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(k == arr[mid]) return mid;
        else if(k < arr[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int rotation(const vector<int>& arr, const int& k){
    int len = arr.size();
    int left = 0;
    int right = len - 1;
    int pivot = -1;


    if (arr[left] <= arr[right]) {
        return Bsearch(arr, 0, len - 1, k);
    }

    while(left <= right){
        int mid = left + (right - left) / 2;
        int next = (mid + 1) % len;
        int prev = (mid + len - 1) % len;

        if(arr[mid] >= arr[next] && arr[mid] >= arr[prev]){
            pivot = mid;
            break;
        }
        else if(arr[mid] >= arr[left]) left = mid + 1;
        else right = mid - 1;
    }

    int ans = Bsearch(arr, 0, pivot, k);
    if(ans != -1) return ans;
    
    return Bsearch(arr, pivot + 1, len - 1, k);
}

int main(){
    vector<int> arr{11,12,15,18,2,5,6,8};
    int k = 5;
    cout << rotation(arr, k); // Outputs: 5
    return 0;
}