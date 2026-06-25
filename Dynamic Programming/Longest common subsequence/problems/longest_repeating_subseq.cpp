//problem statement -> logic -> code variation
//input: arr[string]
//task: find longest repeating subsequence (order matters; can be discontinuous) that repeat itself
//ex: "aabebcdd" -> "abd" and "abd" we can find two of these and repeat itself ( find the longest one)
//output: print the length of largest subsequence

#include <iostream>
#include <vector>
using namespace std;

int lrs(const string& s){
    int len = s.size();
    string k = s;

    vector<vector<int>> t(len+1, vector<int>(len+1, 0));

    for(int i = 1; i < len+1; i++){
        for(int j = 1; j < len+1; j++){
            if(s[i-1]==k[j-1] && i != j){
                t[i][j] = t[i-1][j-1] + 1;
            }else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }

    return t[len][len];
}

int main(){
    string s = "aabebcdd";
    cout<<lrs(s);
    return 0;
}

/*
 * Explanation:
 * This file finds the Longest Repeating Subsequence (LRS) in a string.
 * It uses the LCS logic where the string is compared with itself (`s` and `k = s`).
 * The key difference from standard LCS is the condition `i != j`.
 * When characters match but their indices are different (`s[i-1] == k[j-1] && i != j`), it contributes to the repeating subsequence.
 * This ensures that a character at the same position isn't counted as a repeat of itself.
 */
