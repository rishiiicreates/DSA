
// max heap: smallest element
// max heap: -> top() = greatest element

// for element: 7 10 4 3 20 15 (not necessary to be sorted)
// return heap top at last

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int smallest(const vector<int> arr, int k){
    
    priority_queue<int> maxh;
    int len = arr.size();
    
    for(int i = 0; i < len; i++){
        maxh.push(arr[i]);

        if( maxh.size() > k){
            maxh.pop();
        }
        
    }
    return maxh.top();
}

int main(){
    vector<int> arr{7,10,4,3,20,15};
    int k = 3;
    cout<<smallest(arr,k);
    return 0;
}
