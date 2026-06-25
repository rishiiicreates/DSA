//problem: convert str1 into str2
//operation: insert or delete ( if replace, then the famous question "edit distance")
//ex:input -> str1 = heap, str2 = pea;
//   output -> no of insertion and deletion ( p + heap = +1 insetrion, pheap - {h,p} = +2 deletion)
//          -> 1 delete, 2 insert


//problem -> how to apply -> relate lcs -> code variation
//pattern: lcs -> two string + optimal = lcs question
//relate lcs -> pattern matching algo -> same type of input and output


#include <iostream>
#include <vector>
using namespace std;

pair<int,int> editlcs(const string& x, const string y){
    int n = x.size();
    int m = y.size();

    vector<vector<int>> t(n + 1, vector<int>(m+1, 0));

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
            if(x[i-1] == y[j-1]){
                t[i][j] = t[i-1][j-1] +1;
            }else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    int insert = n - t[n][m];
    int deletion = m - t[n][m];
    pair<int,int> ans = make_pair(insert, deletion);
    return ans;
}

int main(){
    string x = "heap";
    string y = "pea";
    pair<int,int> ans = editlcs(x, y);
    cout<<"Deletion:"<<ans.first << " " << "Insertion:" << ans.second;
    return 0;
}

/*
 * Explanation:
 * This file solves the problem of finding the minimum number of insertions and deletions required to convert string 'x' to string 'y'.
 * The logic is built upon the Longest Common Subsequence (LCS).
 * The characters that are part of the LCS do not need to be changed.
 * Therefore, the deletions required from 'x' are the characters not in the LCS (`n - lcs_length`).
 * The insertions required into 'x' (to match 'y') are the characters in 'y' that are not in the LCS (`m - lcs_length`).
 */


