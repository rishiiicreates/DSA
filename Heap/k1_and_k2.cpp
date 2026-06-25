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

/*
 * Explanation:
 * This algorithm calculates the sum of all elements in the array that are strictly greater than the k1-th smallest element and strictly smaller than the k2-th smallest element.
 * It uses a max-heap to keep track of the 'k2' smallest elements. Elements are pushed into the max-heap, and if the heap size exceeds 'k2', the largest element is popped.
 * After iterating through the array, the top of the max-heap is the k2-th smallest element. It is popped to exclude it from the sum.
 * Then, the remaining elements are popped and added to the sum until the heap size reduces to 'k1', thus excluding the k1 smallest elements.
 * The resulting sum is returned.
 */