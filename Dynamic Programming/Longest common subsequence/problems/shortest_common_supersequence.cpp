//problem statement -> code variation
//input: two strings( arr[str1], arr[str2])
//output asked: create shortest string that constains both string( # basically create smallest union of str1 and str2)
//ex1: input: str1 "geek", str1 = "eke"
//    output: "geeke" # order should be same for each character, but strings can be sequence could be change: ekeeg == geeke
//ex2: input: str1 = "aggtab", str2 = "gxtxayb"
//     output: "aggxtxayb"

#include <iostream>
#include <vector>
using namespace std;

int scs(const string& x, const string& y){
    int n = x.size();
    int m = y.size();

    vector<vector<int>> t(n+1, vector<int>(m+1, 0));
    int mx = 0;

    //concept: (#lcs) -> string1 + string2 = total string lenght
    // fn(lcs) -> int(x); x -> common subsequence -> total string - x = shortest common supersequence
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
            if(x[i-1] == y[j-1]){
                t[i][j] = t[i-1][j-1] + 1;
                mx = t[i][j] > mx ? t[i][j] : mx ;
            }else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }

    return ((n+m)-t[n][m]);
}

int main(){
    string x = "aggtab";
    string y = "gxtxayb";

    cout << scs(x, y);
    return 0;
}

/*
 * Explanation:
 * This file calculates the length of the Shortest Common Supersequence (SCS) of two strings.
 * An SCS is the shortest string that has both input strings as subsequences.
 * Conceptually, if you concatenate both strings, you double-count the characters they have in common (their LCS).
 * Therefore, the length of the SCS is optimally derived by summing the lengths of both strings and subtracting the length of their LCS: `(n + m) - lcs_length`.
 */