#include <iostream>
#include <vector>
using namespace std;
// storing flag data

stack<int> s;
int minElement = -1;

void push(int i){
    if(s.empty()){
        s.push(i);
        minElement = i;
    }else{
        if(i >= minElement) s.push(i);
        else if( i < minElement){
            s.push(2*i - minElement);
            minElement = i;
        }
    }
}


int getMin(){
    if(s.empty()) return -1;
    return minElement;
}

void pop(){
    if(s.empty()){
        return;
    }
    else{
        if(s.top() >= minElement){
            s.pop();
        }
        else if( s.top() < minElement){
            minElement = 2*minElement - s.top();
            s.pop();
        }
    }
}

int top(){
    if (s.empty()) return -1;
    else{
        if (s.top() >= minElement){
            return s.top();
        }else if(s.top() < minElement){
            return minElement;
        }
    }
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