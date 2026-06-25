#include <iostream>
#include <vector>
using namespace std;


// removing the idea of recursive call
// storing the whole data in a matrix
// recursive code -> DP (either by memoization or top-down)
// ommiting recursive code + top-down = DP

//step 1: initialization
//step 2: swapping recursive function with itetative function


//converting the conditions: 
    // if(wt[len-1] <= W){
    //     t[len][W] = max(val[len-1] + t[W-wt[len-1]][len-1], t[len-1][W]);
    // }

    // else if(wt[len - 1] > W){
    //     t[len][W] = t[len - 1][W];
    // }



// i = length
// j = weight

int knapsack(vector<int>& wt, vector<int>& val, int W, int len){

    //initialization
    vector<vector<int>> t(len + 1, vector<int>(W + 1, 0));

    //diagram
    for(int i = 1; i < len + 1; i++){
        for(int j = 1; j < W + 1; j++){
            if(wt[i-1] <= j){
                t[i][j] = max(val[i-1] + t[i-1][j - wt[i-1]],t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[len][W];
}


int main(){
    vector<int> wt { 1,3,4,5};
    vector<int> val { 1,4,5,7};

    int W = 7;
    cout<<knapsack(wt, val, W, wt.size() - 1);
    return 0;
}

/*
 * Explanation:
 * This file implements the 0-1 knapsack problem using a bottom-up (iterative) 
 * dynamic programming approach. It eliminates the recursion entirely and builds the 
 * solution matrix step-by-step from base conditions up to the target capacity.
 */


