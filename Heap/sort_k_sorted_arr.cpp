//the array is partially sorted (brute force: n(logn))
//each value can only have a deviation of +k to -k indices
//sliding window type question

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> solve(const vector<int>& arr, const int& k){
    int len = arr.size();
    priority_queue<int, vector<int>, greater<int>> minh;
    vector<int> ans;

    for(int i = 0; i < len; i++){
        if(minh.size() > k){
            ans.push_back(minh.top());
            minh.pop();
        }
        minh.push(arr[i]);
    }
    while(!minh.empty()){
        ans.push_back(minh.top());
        minh.pop();
    }
    return ans;
}

int main(){
    vector<int> arr{6,5,3,2,8,10};
    int k = 4;
    vector<int> ans = solve(arr,k);
    for(int i: ans) cout << i <<endl;
    return 0;
}