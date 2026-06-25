#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> NSL(const vector<int>& arr){
    int n = arr.size();
    vector<int> v;
    stack<int> s;

    for(int i = 0; i < n; i++){
        
        while(s.size() > 0 && s.top() >= arr[i]){
            s.pop();
        }
        if(s.empty()){
            v.push_back(-1);
        }else{
            v.push_back(s.top());
        }
        s.push(arr[i]);    
    }
    return v;
}   


int main(){
    vector<int> arr{4,5,2,10,8};
    vector<int> result = NSL(arr);
    for(int x: result){
        cout << x << " " ;
    }
    return 0;
}

/*
 * Explanation:
 * This algorithm finds the Nearest Smaller Element (NSE) to the left for every element in an array.
 * It uses a stack to store the elements as it iterates from left to right.
 * For each element, it repeatedly pops elements from the stack if they are greater than or equal to the current element. This maintains a monotonically increasing stack.
 * If the stack becomes empty, it implies no smaller element exists to the left, so `-1` is appended. Otherwise, the top element of the stack is the NSE.
 * Time complexity is O(N) because each element is pushed and popped at most once.
 */