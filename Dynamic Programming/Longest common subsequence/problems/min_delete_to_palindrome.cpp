//problem statement -> logic -> code variation
//input: arr[sting]
//minimum deletion to make panlindrome

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dlp(const string& s){
    int n = s.size();
    string r = s;
    reverse(r.begin(), r.end());

    vector<vector<int>> t(n+1, vector<int>(n+1, 0));

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            if(s[i-1] == r[j-1]){
                t[i][j] = t[i-1][j-1] + 1;
            }
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    return (n-t[n][n]);
}

int main(){
    string s = "agbcba";
    cout<<dlp(s);
    return 0;
}

/*
 * Explanation:
 * This file calculates the minimum number of deletions required to make a string a palindrome.
 * The logic leverages the Longest Palindromic Subsequence (LPS).
 * Any character that is not part of the LPS must be deleted to form a palindrome.
 * Thus, the minimum deletions required is simply the length of the string minus the length of its LPS (`n - t[n][n]`).
 */

