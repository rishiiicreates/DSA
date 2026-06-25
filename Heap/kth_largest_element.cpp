//input: arr[], int[k]
//output: arr[];
//return all k largest element

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> largest(const vector<int>& arr,const int& k){
    int len = arr.size();

    //min heap because largest element
    priority_queue<int, vector<int>, greater<int>> minh;
    vector<int> ans;

    for(int i = 0;i  < len; i++){
        minh.push(arr[i]);
        if(minh.size() > k){
            minh.pop();
        }
    }
    while(!minh.empty()){
        ans.push_back(minh.top());
        minh.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> arr{7,10,4,3,20,15};
    int k = 2;
    vector<int> ans = largest(arr,k);
    for(int i: ans) cout << i <<endl;
    return 0;
}

/*
 * Explanation:
 * This algorithm finds all 'k' largest elements in an array.
 * It uses a min-heap to keep track of the 'k' largest elements seen so far.
 * As elements are processed, they are pushed into the min-heap. Because it's a min-heap, the smallest of the top 'k' elements is at the top.
 * If the heap size exceeds 'k', the top element (the smallest one) is popped out, ensuring the heap only contains the 'k' largest elements.
 * After evaluating all elements, the remaining 'k' elements in the heap are extracted, reversed (to order them from largest to smallest), and returned.
 */
