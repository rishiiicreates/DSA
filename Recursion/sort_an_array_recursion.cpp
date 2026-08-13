// sorting array using recursion

#include <iostream>
using namespace std;

void insert(vector<int>& arr, int value){
    if(arr.empty() || arr.back() <= value){
        arr.push_back(value);
        return;
    }

    int last = arr.back();
    arr.pop_back();
    insert(arr, value);
    arr.push_back(last);
}

vector<int> sorting(const vector<int>& arr){
    
    //base condition
    if(arr.size() <= 1) return arr;
    
    //hypothesis
    vector<int> ans = sorting(vector<int>(arr.begin(), arr.end() - 1));

    //induction
    insert(ans, arr.back());
     
    return ans;

}

int main(){
    vector<int> arr{3,2,4,6,5,9,7};
    vector<int> ans =  sorting(arr);
    for(int i : ans) cout << i << " ";
    return 0;
}