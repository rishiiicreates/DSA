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
    return 0;
}
