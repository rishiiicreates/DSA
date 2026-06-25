// knapsack where we can repeat elements and we want to maximize the value of the knapsack

// if item rejected and processed then we can't repeat.
// if item accepted then not precessed and we can repeat the item.

//step:

//1) process item: not taken -> processed
//2) process item: taken -> not processed

//code:

#include <iostream>
#include <vector>
using namespace std;

int unboundsack(vector<int>& arr,vector<int>& length, int S){
    int len = arr.size();
    vector<vector<int>> t(len+1, vector<int>(S + 1, 0));

    for(int i = 0; i < len + 1; i++){
        t[i][0] = 1;
    }

    for(int i = 1; i < len + 1; i++){
        for(int j = 1; j < S + 1; j++){
            if ( arr[i - 1] <= j){
                t[i][j] = max(length[i-1] + t[i][j - arr[i-1]], t[i-1][j]);
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[len][S];
}

/*
 * Explanation:
 * This file implements the basic unbounded knapsack problem. 
 * Items can be selected multiple times without restrictions, optimizing the value 
 * based on capacity.
 */