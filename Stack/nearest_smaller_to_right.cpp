#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> NSR(const vector<int>& arr){
    int n = arr.size();
    vector<int> v;
    stack<int> s;

    for(int i = n-1; i >= 0; i--){
        if(s.size()==0){
            v.push_back(-1);
        }
        else if(s.size() > 0 && s.top() < arr[i]){
            v.push_back(s.top());
        }
        else if(s.size() > 0 && s.top() >= arr[i]){
            while(s.size() > 0 && s.top() >= arr[i]){
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
    vector<int> arr {4,5,2,10,8};
    vector<int> result = NSR(arr);
    for(int x: result){
        cout << x << " ";
    }
    return 0;
}