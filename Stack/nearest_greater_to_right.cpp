#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> NGR(const vector<int>& arr){
    int n = arr.size();
    vector<int> v;
    stack<int> s;

    for(int i = n-1; i >= 0; i--){
        if (s.size() == 0){
            v.push_back(-1);
        }else if (s.size() > 0 && s.top() > arr[i]){
            v.push_back(s.top());
        }else if (s.size() > 0 && s.top() <= arr[i]){
            while(s.size() > 0 && s.top() <= arr[i]){
                s.pop();
            }
            if(s.size() == 0){
                v.push_back(-1);
            }else{
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}


int main(){
    vector<int> arr{1,4,6,4,7,23};
    vector<int> result = NGR(arr);
    for(int x : result){
        cout << x << " ";
    }
    return 0;
}

/*
 * Explanation:
 * This algorithm finds the Next Greater Element (NGE) to the right for every element in an array.
 * It uses a stack to keep track of elements whose next greater element is not yet found.
 * By traversing the array from right to left, it maintains a monotonically decreasing stack (from bottom to top).
 * For each element, it pops all elements from the stack that are smaller than or equal to the current element.
 * If the stack becomes empty, there is no greater element to the right, so `-1` is assigned. Otherwise, the top of the stack is the NGE.
 * Finally, it reverses the result array to match the original array's order. Time complexity is O(N) since each element is pushed and popped at most once.
 */