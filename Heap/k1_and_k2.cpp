//input: arr[], int k1, int k2
//output: find sum between k1th and k2th smallest element

#include <iostream>
#include <queue>
using namespace std;

int solve(const vector<int>& arr, int k1, int k2){
    int len = arr.size();
    priority_queue<int> maxh;

    for(int i = 0; i < len; i++){
        maxh.push(arr[i]);
        if(maxh.size() > k2){
            maxh.pop();
        }
    }

    int ans = 0;
    maxh.pop();
    while(maxh.size() > k1){
        ans += maxh.top();
        maxh.pop();
    }
    return ans;
}

int main(){
    vector<int> arr{1,3,12,5,15,11};
    int k1 = 3;
    int k2 = 6;
    cout << solve(arr,k1,k2);
    return 0;
}