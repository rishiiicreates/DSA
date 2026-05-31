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