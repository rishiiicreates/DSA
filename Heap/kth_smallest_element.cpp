
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

/*
 * Explanation:
 * This algorithm finds the k-th smallest element in an array.
 * It uses a max-heap to keep track of the 'k' smallest elements seen so far.
 * Elements are pushed into the max-heap. Since it's a max-heap, the largest element among the current 'k' elements is at the top.
 * If the size of the heap exceeds 'k', the top element is popped, ensuring that the heap only stores the 'k' smallest elements.
 * After iterating through all elements, the top of the max-heap is exactly the k-th smallest element, which is returned.
 */
