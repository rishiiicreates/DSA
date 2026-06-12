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
    vector<long long> arr = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target = 23;
    int result = solve(arr, target);
    
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the vector." << endl;
    }
    return 0;
}