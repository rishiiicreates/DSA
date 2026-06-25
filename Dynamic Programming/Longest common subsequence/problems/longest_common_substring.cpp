//problem statement -> identification -> code variation
//input: two substring[arr] given
//longest common substing ( # should be continuous ) -> no subsequence char, only continuous char
//Common: lcs(str 1, str2) ~ lcsubstr(str 1, str 2) -> same input, lc ~ same in both, same output <int> (length)



#include <iostream>
#include <vector>
using namespace std;

int lcsubstring(const string& x, const string& y){
    int n = x.size();
    int m = y.size();
    int maximum = 0;

    vector<vector<int>> t(n+1, vector<int>(m+1, 0));

    
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
            if(x[i-1] == y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
                maximum = t[i][j] > maximum ? t[i][j] : maximum ;
            }

        }
    }
    return maximum;
}

int main(){
    string x = "abedgh";
    string y = "abfhrgh";
    
    cout<< lcsubstring(x, y);
    return 0;
}

/*
 * Explanation:
 * This file implements an algorithm to find the Longest Common Substring between two strings.
 * Unlike a subsequence, a substring must be contiguous.
 * It uses a top-down DP approach similar to LCS. If characters match, `t[i][j] = 1 + t[i-1][j-1]` and a `maximum` variable is updated.
 * If characters do NOT match, we don't carry over previous values like in LCS. The default 0 initialization handles the reset.
 * The maximum length found anywhere in the DP table is returned.
 */

