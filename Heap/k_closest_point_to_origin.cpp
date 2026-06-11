//input: arr[pair<int,int>], int k;
//problem statement: find k closest point to origin in the given 2D array
//finding closest to origin by distance formula: √(x1-x2)^2 + (y1-y2)^2) // btw, we can remove underoot, because we just want to compare them

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, pair<int,int>> p;

vector<pair<int,int>> solve(const vector<vector<int>>& arr,const int& k){
    int len = arr.size();
    priority_queue <p> maxh;

    for(auto i = 0; i < len ; i++){
        int dist = arr[i][0]^2 + arr[i][1]^2;
        maxh.push({dist, {arr[i][0], arr[i][1]}});
        if(maxh.size() > k){
            maxh.pop();
        }
    }

    vector<pair<int,int>> ans;
    while(!maxh.empty()){
        ans.push_back({maxh.top().second.first, maxh.top().second.second});
        maxh.pop();
    }
    return ans;
}

int main(){
    vector<vector<int>> arr{
        {1,3},
        {-2,2},
        {5,8},
        {0,1}
    };
    int k = 2;
    vector<pair<int,int>> ans = solve(arr,k);
    for(auto i : ans){
        cout<< "{" << i.first << "," << i.second<< "}" << endl;
    }
    return 0;
}