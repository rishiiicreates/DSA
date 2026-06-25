//problem statement -> initialization -> code variation
//give: sum, arr[coin];
//task: give the summation with least count of coin that equals to sum();
//output: least count of coint that sums up to 5;



#include <iostream>
#include <vector>
using namespace std;

int mincoin(vector<int>& coin, int sum){
    int len = coin.size();
    // storing infinity(INT_MAX) because ive to sum infinitly to add up to given sum with 0 coin;(INT_MAX -1: safty purpose)
    vector<vector<int>> t(len + 1, vector<int>(sum+1, INT_MAX - 1));
    for(int i = 1; i < len + 1; i++){
        t[i][0] = 0;
    }

    for(int i = 1; i < len + 1; i++){
        for(int j = 1; j < sum + 1; j++){
            if(coin[i-1] <= j){
                t[i][j] = min(1 + t[i][j - coin[i-1]], t[i-1][j]);
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return (t[len][sum] == INT_MAX - 1 ? -1 : t[len][sum]);
}

int main(){
    vector<int> arr{1,2,3};
    int sum = 5;
    cout<< mincoin(arr, sum);
    return 0;
}

/*
 * Explanation:
 * This file addresses another variation of the coin change problem: finding the 
 * minimum number of coins needed to make up a given sum. It initializes the matrix 
 * with infinity and iteratively finds the minimum coins by either including or excluding each coin.
 */



