#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> t;

int solve(const string& a, const string& b){
    int n = a.length();

    //base condition
    if(a.empty() && b.empty()) return false;
    if(a.compare(b) == 0) return true;
    
    bool flag = false;

    for(int i = 1; i < n; i++){
        if(solve(a.substr(0,i), b.substr(n-i,i)) == true && solve(a.substr(n-i, i), b.substr(0,i)) == true){
            flag = true;
        }
        if(solve(a.substr(0,i), b.substr(0,i)) == true && solve(a.substr(n-i,i), b.substr(n-i,i)) == true){
            flag = true;
        }
    }
    return t[n][n] = flag;
}
int main(){
    string a;
    string b;
    cin>>a>>b;
    if(a.length() != b.length()) return 1;
    if(a.empty() && b.empty()) return 1;
    t.assign(a.length()+1, vector<int>(a.length()+1, 0));
    int ans = solve(a,b);
    cout<< ((ans > 0) ? "True" : "False");
    return 0;
}

/*
 * Explanation:
 * This file attempts to implement the memoized version of the Scrambled String problem, which checks if one string is a scrambled version of another. It tries to use a 2D vector `t` to cache results to avoid redundant calculations. However, the memoization implementation is incomplete as it currently does not effectively map the substring states to the 2D vector indices. It follows the same recursive logic as the pure recursive approach: trying every split point `i` and checking both the swapped and unswapped subtree scenarios.
 */
