//deleting middle element in stack
//input: stack<int>
//output: print stack without middle element
//middle element = size/2 + 1

#include <iostream>
#include <stack>
using namespace std;

stack<int> solve(stack<int>& stk, int mid){

    //edge case
    if(stk.empty()) return stk;

    //base element
    if(mid == 1){
        stk.pop();
        return stk;
    }


    //hypothesis
    int last = stk.top();
    stk.pop();
    solve(stk, mid-1);

    //induction
    stk.push(last);

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
    int mid = stk.size()/2 + 1;
    stack<int> ans = solve(stk, mid);
    while(!ans.empty()){
        cout<<ans.top() << endl;
        ans.pop();
    }
    return 0;
}