//asks: for each day; consecutive smaller or equal before it including the number itself( a type of NGL)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> SSP(const vector<int>& arr){
    vector<int> v;
    int n = arr.size();
    stack<pair<int, int>> s;

    for(int i = 0; i < n; i++){
        while (!s.empty() && s.top().second <= arr[i]){
            s.pop();
        }
        if(s.empty()){
            v.push_back(i+1);
        }
        else{
            v.push_back(i-s.top().first)
        }
        s.push(make_pair(i, arr[i]));
    }
    return v;
}

int main(){
    vector<int> arr{100, 80, 60, 70, 60, 75, 85};
    vector<int> result = SSP(arr);

    for(int x: result){
        cout << x << " ";
    }
    return 0;
}