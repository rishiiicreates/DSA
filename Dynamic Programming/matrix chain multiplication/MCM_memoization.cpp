

#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> t;

int solve(const vector<int>& arr, int i, int j){
    //base condition:
    if(i >= j) return 0;

    if(t[i][j] != -1) return t[i][j];
    int mn = INT_MAX;


    for(int k = i; k < j; k++){
        int temp = solve(arr, i, k) + solve(arr, k+1, j) + (arr[i-1]*arr[k]*arr[j]);

        mn = min(mn, temp);
    }

    return t[i][j] = mn;
}

int main(){
     
    vector<int> arr{40,20,30,10,30};
    int i = 1; // temp = arr[i-1][k] / arr[k+1][j]
    int j = arr.size() - 1;
    t.assign(j+1, vector<int>(j+1, -1));

    cout<<solve(arr,i,j);
    return 0;
}