#include <iostream>
#include <vector>
using namespace std;

int countsum(vector<int>& arr, int sum){
    
    //initialization:
    int len = arr.size();
    vector<vector<int>> t(len + 1, vector<int>(sum+1, 0));
    for(int i = 0; i < len+1; i++){
        t[i][0] = 1;
    }

    //diagram
    for(int i = 1; i < len + 1; i++){
        for(int j = 1; j < sum + 1; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];

            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[len][sum];
}

int main(){
    vector<int> arr{2,3,5,6,8,10};
    int sum = 10;
    int result = countsum(arr, sum);
    cout<<result;
    return 0;
}

/*
 * Explanation:
 * This file calculates the total number of subsets of an array that sum up 
 * to a specific given value, utilizing a variation of the 0-1 knapsack approach 
 * where possibilities are summed instead of maximized.
 */