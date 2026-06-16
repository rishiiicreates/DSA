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