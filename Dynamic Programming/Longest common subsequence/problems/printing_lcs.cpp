//problem statement -> identification -> how to solve -> code variation
//longest common substring; but asking to print the longest common substring 


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string lcsp(const string& x, const string& y){
    int n = x.size();
    int m = y.size();

    vector<vector<int>> t(n+1, vector<int>(m+1, 0)); 

    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < m + 1; j++){
            if(x[i-1] == y[j-1]){
                t[i][j] = t[i-1][j-1] + 1;
                
            }
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }

    string lcs = "";
    while( n != 0 && m != 0){
        if(x[n-1] == y[m-1]){
            lcs.push_back(x[n-1]);
            n--;
            m--;
        }else{
            if(t[n-1][m] > t[n][m-1]){
                n--;
            }else{
                m--;
            }
            
        }
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main(){
    string x = "abedghrfgerfgrfnvjf";
    string y = "abedfhrfgeriouhgfref";
    
    cout<< lcsp(x, y);
    return 0;
}

/*
 * Explanation:
 * This file demonstrates how to print the Longest Common Subsequence (LCS) rather than just finding its length.
 * First, the standard 2D DP table `t` is populated.
 * Then, it traces back from the bottom-right corner `t[n][m]`:
 * - If `x[n-1] == y[m-1]`, this character is part of the LCS. It's added to a string, and we move diagonally (`n--`, `m--`).
 * - If they don't match, we move in the direction of the larger DP value (either up `n--` or left `m--`).
 * Since the traceback constructs the string backwards, the result is reversed before returning.
 */
