//input: arr[]
//problem statement: connect ropes with minimum cost
//cost: ∑ (arr[i]+ arr[j])
//output: minimum cost to do so. # add mimimum two elements to get minimal cost

#include <iostream>
#include <queue>
using namespace std;

int solve(const vector<int>& arr){
    int len = arr.size();
    priority_queue<int, vector<int>, greater<int>> minh;

    for(int i = 0; i < len; i++){
        minh.push(arr[i]);
    }
    while(minh.size()>=2){
        int temp = minh.top();
        minh.pop();
        temp += minh.top();
        minh.pop();
        minh.push(temp);
    }
    return minh.top();
}

int main(){
    vector<int> arr { 1,2,3,4,5};
    cout << solve(arr);
    return 0;
}

