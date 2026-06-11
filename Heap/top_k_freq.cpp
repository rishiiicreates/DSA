//input: arr[], int k
//task: output k most frequent no.
//output: arr[]


#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

vector<pair<int,int>> solve(const vector<int>& arr, const int& k){
    int len = arr.size();

    unordered_map<int, int> mp; 
    for(int i = 0; i < len; i++){
        mp[arr[i]]++;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minh;
    for(auto i = mp.begin(); i != mp.end(); i++){
        minh.push({i->second, i->first});
        if(minh.size()>k) minh.pop();
    }

    vector<pair<int,int>> ans;
    while(!minh.empty()){
        ans.push_back({minh.top().second,minh.top().first});
        minh.pop();
    }
    return ans;
}

int main(){
    vector<int> arr = {1,1,1,2,3,3,4,5};
    int k = 2;
    vector<pair<int,int>> ans = solve(arr,k);
    for(auto i: ans){
        cout<< i.first << "->" << i.second << endl;
    }
    return 0;
}
