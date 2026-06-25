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

/*
 * Explanation:
 * This algorithm sorts a 'k-sorted' array (where each element is at most 'k' positions away from its target sorted position) efficiently.
 * It maintains a min-heap of size at most 'k + 1'. As elements are processed, they are pushed into the min-heap.
 * When the heap size exceeds 'k', it guarantees that the minimum element currently in the heap is the smallest among all remaining unsorted elements, because elements can be displaced by at most 'k' positions.
 * The top element is popped and placed in the sorted answer array.
 * Finally, any remaining elements in the heap are popped and appended to the answer array in sorted order.
 */