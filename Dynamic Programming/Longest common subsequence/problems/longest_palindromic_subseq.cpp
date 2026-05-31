//problem statement -> relating to lcs -> code variation

//input: string
//output: int
//task: find largest palindrome subsequence

// find lcs -> filter palindromic one -> get the longest


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lps(const string& s){
    int n = s.size();
    string k = s;
    reverse(k.begin(), k.end());


    vector<vector<int>> t(n+1, vector<int>(n+1, 0));

    for(int i = 1; i< n+1; i++){
        for(int j = 1; j < n+1; j++){
            if(s[i-1]==k[j-1]){
                t[i][j] = t[i-1][j-1] + 1;
            }else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    return t[n][n];
}


int main(){
    string a = "agbcba";
    cout<<"Longenst Common Subsequence:"<< lps(a);
    return 0;
}