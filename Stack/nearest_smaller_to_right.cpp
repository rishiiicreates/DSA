#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> NSR(const vector<int>& arr){
    int n = arr.size();
    vector<int> v;
    stack<int> s;

    for(int i = n-1; i >= 0; i--){
        if(s.size()==0){
            v.push_back(-1);
        }
        else if(s.size() > 0 && s.top() < arr[i]){
            v.push_back(s.top());
        }
        else if(s.size() > 0 && s.top() >= arr[i]){
            while(s.size() > 0 && s.top() >= arr[i]){
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
    vector<int> arr {4,5,2,10,8};
    vector<int> result = NSR(arr);
    for(int x: result){
        cout << x << " ";
    }
    return 0;
}

/*
 * Explanation:
 * This algorithm finds the Nearest Smaller Element (NSE) to the right for every element in an array.
 * It uses a stack and iterates through the array from right to left, which helps in finding the next smaller element efficiently.
 * For each element, it pops elements from the stack as long as they are greater than or equal to the current element. This keeps the stack in a monotonically increasing order (from bottom to top).
 * If the stack becomes empty, no smaller element exists to the right, so `-1` is assigned. Otherwise, the top element of the stack is the NSE.
 * After processing all elements, the result array is reversed to match the original array's order. Time complexity is O(N).
 */