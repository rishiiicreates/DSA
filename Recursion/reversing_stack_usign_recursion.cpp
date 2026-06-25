//reversing stack using recursion

#include <iostream>
#include <stack>
using namespace std;

void insert(stack<int>& stk, int ele){
    
    if(stk.empty()){
        stk.push(ele);
        return;
    }
    int temp = stk.top();
    stk.pop();
    insert(stk,ele);
    stk.push(temp);
}   

stack<int> solve(stack<int>& stk){

    //base condition
    if(stk.size() <= 1) return stk;

    int ele = stk.top();
    stk.pop();

    //hypothesis
    solve(stk);

    //induction
    insert(stk,ele);

    return stk;
}

int main(){
    int len;
    cout<< "Enter size of stack:";
    cin>>len;
    stack<int> stk;

    for(int i = 0; i < len; i++){
        int element;
        cout<<"Enter element "<< i+1 << ":  ";
        cin>>element;
        stk.push(element);
    }
    stack<int> ans = solve(stk);
    while(!ans.empty()){
        cout<<ans.top() << endl;
        ans.pop();
    }
    return 0;
}

/*
 * Explanation:
 * This algorithm recursively reverses a stack without using any auxiliary data structure.
 * It uses the Hypothesis-Induction-Base Condition approach with two recursive functions:
 * 1. solve(stk): 
 *    - Base Condition: If the stack has 1 or fewer elements, it's already reversed.
 *    - Hypothesis: We pop the top element and recursively reverse the rest of the stack.
 *    - Induction: We use the `insert` helper function to place the popped element at the very bottom of the now-reversed stack.
 * 2. insert(stk, ele):
 *    - Base Condition: If the stack is empty, push the element.
 *    - Hypothesis: Pop the top element and recursively call `insert` to reach the bottom.
 *    - Induction: Push the previously popped element back on top.
 */