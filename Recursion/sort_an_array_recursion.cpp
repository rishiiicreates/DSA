// sorting array using recursion

#include <iostream>
using namespace std;

void insert(vector<int>& arr, int value){
    if(arr.empty() || arr.back() <= value){
        arr.push_back(value);
        return;
    }

    int last = arr.back();
    arr.pop_back();
    insert(arr, value);
    arr.push_back(last);
}

vector<int> sorting(const vector<int>& arr){
    
    //base condition
    if(arr.size() == 1) return arr;
    
    //hypothesis
    vector<int> ans = sorting(vector<int>(arr.begin(), arr.end() - 1));

    //induction
    insert(ans, arr.back());
     
    return ans;

}

int main(){
    vector<int> arr{3,2,4,6,5,9,7};
    vector<int> ans =  sorting(arr);
    for(int i : ans) cout << i << " ";
    return 0;
}

/*
 * Explanation:
 * The array is sorted using a recursive approach consisting of two main functions: `sorting` and `insert`.
 * 
 * 1. Base Case: If the array has only 1 element, it is already sorted, so we return it.
 * 2. Hypothesis: We recursively sort the array minus the last element. We assume the recursive call `sorting(vector<int>(arr.begin(), arr.end() - 1))` successfully sorts the N-1 elements and returns a sorted array.
 * 3. Induction: Once we have the sorted array of N-1 elements, we need to insert the `arr.back()` (the Nth element we left out) into its correct sorted position. We do this using the `insert` function.
 * 4. The `insert` function also works recursively:
 *    - Base Case: If the array is empty or the last element is smaller than or equal to the value to insert, we simply push the value to the back and return.
 *    - Recursive Step: Otherwise, we pop the last element (which is larger than our value), recursively call `insert` to place our value in the remaining array, and then push the popped element back.
 */