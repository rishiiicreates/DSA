#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> NGR(const vector<int>& arr){
    int n = arr.size();
    vector<int> v;
    stack<int> s;

    for(int i = n-1; i >= 0; i--){
        if (s.size() == 0){
            v.push_back(-1);
        }else if (s.size() > 0 && s.top() > arr[i]){
            v.push_back(s.top());
        }else if (s.size() > 0 && s.top() <= arr[i]){
            while(s.size() > 0 && s.top() <= arr[i]){
                s.pop();
            }
            if(s.size() == 0){
                v.push_back(-1);
            }else{
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}


int main(){
    vector<int> arr{1,4,6,4,7,23};
    vector<int> result = NGR(arr);
    for(int x : result){
        cout << x << " ";
    }
    return 0;
}