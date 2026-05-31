#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


vector<int> NGL(const vector<int>& arr){
    int n = arr.size();
    vector<int> v;
    stack<int> s;

    for(int i = 0; i < n; i++){
        while(s.size() >  0 && s.top() <= arr[i]){
            s.pop();
        }
        if ( s.size() == 0){
            v.push_back(-1);
        }
        else{
            v.push_back(s.top());
        }
        s.push(arr[i]);
    }
    return v;
}

int main(){
    vector<int> arr{1, 3, 2, 4};
    vector<int> result = NGL(arr);
    for(int x: result){
        cout<< x << " ";
    }
    return 0;
}