//two types: 1) maxmimum no of ways
//           2) minimum no of coins

// infinite supply of coins
// given: value of each coin, sum();
//find the number of ways to sumup the sum

#include <iostream>
#include <vector>
using namespace std;

int coinmaxways(vector<int>& coin, int sum){
    int len = coin.size();

    vector<vector<int>> t(len+1, vector<int>(sum+1, false));
    for(int i = 0; i < len + 1; i++ ){
        t[i][0] = 1;
    }

    for(int i = 1; i < len + 1; i++){
        for(int j = 1; j < sum + 1; j++){
            if(coin[i-1] <= j){
                t[i][j] = t[i][j-coin[i-1]] + t[i-1][j];
            }else{
                t[i][j] = t[i-1][j];
            }
        }   

    }
    return t[len][sum];
}

int main(){
    vector<int> arr{1,2,3};
    int sum = 5;
    cout<< coinmaxways(arr, sum);
    return 0;
}

/*
 * Explanation:
 * This file solves the unbounded knapsack variation known as the coin change problem 
 * (maximum ways). It calculates the total number of distinct ways to achieve a given 
 * sum using an infinite supply of coins of specified denominations.
 */
