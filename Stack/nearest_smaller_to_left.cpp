#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> NSL(const vector<int>& arr){
    int n = arr.size();
    vector<int> v;
    stack<int> s;

    for(int i = 0; i < n; i++){
        
        while(s.size() > 0 && s.top() >= arr[i]){
            s.pop();
        }
        if(s.empty()){
            v.push_back(-1);
        }else{
            v.push_back(s.top());
        }
        s.push(arr[i]);    
    }
    return v;
}   


int main(){
    vector<int> arr{4,5,2,10,8};
    vector<int> result = NSL(arr);
    for(int x: result){
        cout << x << " " ;
    }
    return 0;
}