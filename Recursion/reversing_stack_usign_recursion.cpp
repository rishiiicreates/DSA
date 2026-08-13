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

// # Remember: stack = last input -> top, first input -> bottom
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