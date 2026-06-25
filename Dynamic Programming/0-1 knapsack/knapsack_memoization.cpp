#include <iostream>
#include <vector>
using namespace std;

// making matrix for variables those are changing: i.e. Weight(W) and lenght(len)
// of size n*m = t[len+1][W+1]
//memoizations: 
// DP (top-down) = recursive + memoization

//vector<int> t(len+1, vector<int>(W+1));
// memset(t, -1, sizeof(t));


//filling len = 100, W = 1000 using constrains
static vector<vector<int>> t(102, vector<int>(1002, -1));

int knapsack(vector<int>& wt, vector<int>& val, int W, int len){
    //base condition
    if(len==0 || W == 0){
        return 0;
    }
    if(t[len][W] != -1){   //memoizations
        return t[len][W];
    }

    //choice diagram 
    else if(wt[len-1] <= W){
        return t[len][W] = max((val[len-1]) + knapsack(wt, val, W - wt[len-1], len - 1), knapsack(wt, val, W, len -1));
    }
    else if(wt[len-1] > W){
        return t[len][W] = knapsack(wt, val, W, len - 1);
    }

    return 0;
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
 * This file implements the 0-1 knapsack problem using top-down dynamic programming 
 * with memoization. It uses a 2D matrix (t) to cache results of overlapping subproblems 
 * for given lengths and weights, optimizing the recursive choice diagram.
 */



