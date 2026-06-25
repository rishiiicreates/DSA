//sorting stack using recursion

#include <iostream>
#include <stack>
using namespace std;

void insert(stack<int>& stk, int val){

    if(stk.empty() || stk.top() <= val){
        stk.push(val);
        return;
    }

    int last = stk.top();
    stk.pop();
    insert(stk, val);
    stk.push(last);
}

stack<int> sorting(stack<int> stk){

    //base condition
    if(stk.size() <= 1) return stk;

    int last = stk.top();
    stk.pop();

    //hypothesis
    stack<int> ans = sorting(stk);

    //induction
    insert(ans,last);

    return ans;

}

int main(){
    stack<int> stk;
    stk.push(1);
    stk.push(4);
    stk.push(3);
    stk.push(11);
    stk.push(21);

    stack<int> ans = sorting(stk);
    int len = ans.size();

    for(int i = 0; i < len; i++){
        cout<< ans.top() << endl;
        ans.pop();
    }
    return 0;

}

/*
 * Explanation:
 * This algorithm recursively sorts a stack such that the largest elements are at the top.
 * 1. sorting(stk):
 *    - Base Condition: A stack of size 0 or 1 is already sorted.
 *    - Hypothesis: We pop the top element and recursively sort the rest of the stack.
 *    - Induction: We use the `insert` helper function to place the popped element into its correct sorted position.
 * 2. insert(stk, val):
 *    - Base Condition: If the stack is empty or the top element is smaller than or equal to 'val', we push 'val'.
 *    - Hypothesis: Otherwise, we pop the top element and recursively call `insert` to find the right spot.
 *    - Induction: We push the popped top element back onto the stack.
 */