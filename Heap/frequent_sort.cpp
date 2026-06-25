//input: arr[]
//output: sort on basic of frequency

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

vector<pair<int,int>> solve(const vector<int>& arr){

    int len = arr.size();

    unordered_map<int, int> mp;
    for(int i = 0; i < len; i++){
        mp[arr[i]]++;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> minh;
    for(auto i = mp.begin(); i != mp.end(); i++){
        minh.push({i->second, i->first});
    }

    vector<pair<int,int>> ans;
    while(!minh.empty()){
        ans.push_back({minh.top().second, minh.top().first});
        minh.pop();
    }
    return ans;
}

int main(){
    vector<int> arr { 1,2,3,4,2,4,2,4,2,1,4,2,1,4};
    vector<pair<int,int>> ans = solve(arr);
    for(auto i : ans){
        cout<< "number:" << i.first << "->" << "frequency:"<<i.second << endl;
    }
    return 0;
}

/*
 * Explanation:
 * This algorithm sorts an array of elements based on their frequencies in ascending order.
 * It first uses an unordered_map to count the frequency of each element in the array.
 * Then, it iterates over the map and pushes the pairs (frequency, element) into a min-heap.
 * Because a min-heap is used, pairs with the lowest frequency are placed at the top.
 * Finally, elements are popped from the min-heap one by one and their corresponding values are added to the answer vector, producing an array sorted by frequency.
 */