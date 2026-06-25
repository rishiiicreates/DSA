//problem_statement -> why do we need -> code variation
//recursive -> leads subproblem
//memoization -> no same subproblem, only recursive
//top-down -> no recursive, tabular approach

#include <iostream>
#include <vector>
using namespace std;

int lcs(const string& x, const string& y){
    // no recursion so we can initialize length in f(n)
    int n = x.size();
    int m = y.size();
    vector<vector<int>> t(n+1, vector<int>(m+1, -1));
    
    //initializing the first row and column to 0
    for(int i = 0; i < n+1; i++) t[i][0] = 0;
    for(int i = 0; i < m+1; i++) t[0][i] = 0;

    //choice diagram
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
            if(x[i-1] == y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j] , t[i][j-1]);
            }
        }
    }
    return t[n][m];
}

int main(){
    string x = "abcedgh";
    string y = "abdfhr";
    
    cout<< lcs(x, y);
    return 0;
}

/*
 * Explanation:
 * This file implements the Longest Common Subsequence (LCS) algorithm using a tabular approach (bottom-up Dynamic Programming, sometimes referred to as top-down conceptually in this code's comments).
 * It eliminates recursion entirely by iteratively filling a 2D DP table `t`, where `t[i][j]` represents the LCS length for prefixes of lengths `i` and `j`.
 * The table is initialized with 0s for base cases (empty strings). Then, using the choice diagram:
 * If characters match, `t[i][j] = 1 + t[i-1][j-1]`. If they differ, it takes the maximum from excluding either character `max(t[i-1][j], t[i][j-1])`.
 * This approach optimally solves the LCS problem in O(N*M) time and space without call stack overhead.
 */

