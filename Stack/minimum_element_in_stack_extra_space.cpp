#include<iostream>
#include<stack>
using namespace std;

stack<int> s;
stack<int> ss;

void push(int a){
    s.push(a);
    if(ss.empty() || ss.top() >= a) ss.push(a);
}

void pop(){
    if(s.empty()) return;
    if(!ss.empty() && ss.top() == s.top()) ss.pop();
    s.pop();
}

int getMin(){
    if(ss.empty()) return -1;
    else return ss.top();
    return 0;
}


int main(){
    push(18);
    push(19);
    push(28);
    push(15);
    push(15);
    cout<<getMin()<<endl;
    pop();
    cout<<getMin()<<endl;
    pop();
    pop();
    cout<<getMin()<<endl;
    return 0;

}

/*
 * Explanation:
 * This algorithm implements a Stack that can return the minimum element in O(1) time using extra O(N) space.
 * It maintains two stacks: a main stack `s` for storing all elements and a supplementary stack `ss` for storing the minimum elements.
 * During a `push()` operation, the element is pushed into `s`. It is also pushed into `ss` if `ss` is empty or the element is less than or equal to the current minimum (`ss.top()`).
 * During a `pop()` operation, the element is popped from `s`. If it matches the top of `ss` (meaning the minimum is being removed), it is also popped from `ss`.
 * The `getMin()` operation simply returns the top of `ss`, guaranteeing O(1) time complexity. Space complexity is O(N) in the worst case.
 */