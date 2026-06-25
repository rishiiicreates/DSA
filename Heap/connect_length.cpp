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

/*
 * Explanation:
 * This algorithm attempts to find the minimum cost to connect ropes.
 * It uses a min-heap to keep track of rope lengths. All initial rope lengths are pushed into the min-heap.
 * The algorithm iteratively pops the two smallest ropes from the heap, adds their lengths together, and pushes the combined length back into the heap.
 * This process continues until only one combined rope remains in the heap, which is then returned.
 * Note: While this code computes the final combined rope length, to calculate the total minimum cost, it would need to accumulate the intermediate combination costs.
 */

