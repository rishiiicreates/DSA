#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> t;

int solve(const int& e, const int& f){

    if(t[e][f] != -1) return t[e][f];

    if( e <= 1 || f <= 1) return f;

    int ans = INT_MAX;

    for(int i = 1; i < f; i++){
        int temp = max(solve(e-1,i-1), solve(e,f-i)) + 1;
        ans = min(ans, temp);
    }
    return t[e][f] = ans;
}

int main(){
    int e,f;
    cout<< "Enter eggs and floors:";
    cin>>e>>f;
    t.assign(e+1,vector<int>(f+1, -1));
    cout<<"Minimum no of attempts:"<<solve(e,f);
    return 0;
}

/*
 * Explanation:
 * This file implements the Egg Dropping Problem using recursion with memoization (top-down DP). It finds the minimum attempts to determine the critical floor given `e` eggs and `f` floors. To optimize the pure recursive approach, it stores the results of subproblems in a 2D vector `t`. If a state `(e, f)` has already been computed, it retrieves the answer from `t` directly, thereby drastically reducing the time complexity compared to the exponential pure recursive solution.
 */