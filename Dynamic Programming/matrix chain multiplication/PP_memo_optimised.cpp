#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> t;

int palindrome(const string& arr, int i, int j){
    while(i<j){
        if(arr[i] != arr[j]) return 1;
        i++;
        j--;
    }
    return 0;
}

int solve(const string& arr, int i, int j){
    if(i >=j) return 0;

    if(palindrome(arr, i, j) == 0) return 0;

    if(t[i][j] != -1) return t[i][j];

    int mn = j-i;

    for(int k = i; k < j; k++){

        int left = 0, right = 0;

        if(t[i][k] != -1 ) left = t[i][k];
        else{
            left = solve(arr, i, k);
            t[i][k] = left;
        }

        if(t[k+1][j] != -1) right = t[k+1][j];
        else{
            right = solve(arr, k+1, j);
            t[k+1][j] = right;
        }

        int temp = right + left + 1;
        mn = min(mn, temp);
    }
    return t[i][j] = mn;
}


int main(){
    // scheme: k = i to k = j-1 -> fn(i to k) and fn(k+1 to j)
    //         k = i+1 to k = j -> fn(i to k-1) and fn(k to j) 
    string arr = "abc";
    int i = 0;
    int j = arr.size() - 1;
    t.assign(j+1, vector(j+1, -1));
    cout<<solve(arr,i,j);
    return 0;
}

/*
 * Explanation:
 * This file implements an optimized memoization approach for the Palindrome Partitioning problem. It finds the minimum number of cuts needed to partition a string such that every substring is a palindrome. It improves upon standard memoization by checking if the subproblems `left` and `right` (split at `k`) are already computed in the memoization table `t` before making recursive calls. This further prunes the recursion tree, leading to better performance.
 */