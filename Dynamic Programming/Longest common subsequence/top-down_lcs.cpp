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

