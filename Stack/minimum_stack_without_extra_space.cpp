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

/*
 * Explanation:
 * This algorithm implements a specialized Stack that retrieves the minimum element in O(1) time without using an auxiliary stack (O(1) extra space).
 * It uses a clever mathematical encoding to store both the actual value and the minimum element within a single integer.
 * When pushing an element smaller than the current minimum, it pushes the modified value `(2 * new_val - current_min)` and updates `minElement = new_val`. The modified value will always be strictly less than the new minimum, acting as a flag.
 * When popping, if the top element is less than `minElement`, it indicates that the minimum is being removed. The previous minimum is then restored using the formula `(2 * minElement - popped_val)`.
 * This trick ensures that the space complexity remains O(1) while maintaining O(1) time complexity for `push()`, `pop()`, `top()`, and `getMin()`.
 */