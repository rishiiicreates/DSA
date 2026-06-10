//input: arr[], int[k], int[x];
//task:  find k nums that are close to x
//output: arr[]

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> solve(const vector<int>& arr,const int& k,const int& x){
    priority_queue<pair<int,int>> maxh;
    int len = arr.size();

    for(int i = 0; i < len; i++){
        maxh.push({abs(arr[i]-x), arr[i]});
        if(maxh.size() > k){
            maxh.pop();
        }
    }

    vector<int> ans;
    while(maxh.size()> 0){
        ans.push_back(maxh.top().second);
        maxh.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> arr{5,6,7,8,9};
    int x = 7;
    int k = 3;
    vector<int> ans = solve(arr,k,x);
    for(int x: ans){
        cout << x << " ";
    }
    return 0;
}