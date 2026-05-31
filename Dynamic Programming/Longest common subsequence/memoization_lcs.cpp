// removing the recursive calls and using memoization to store the results of previously computed subproblems

#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> t;

int lcs(const string& x, const string& y, int n, int m){
    //base condition
    if(n==0 || m ==0){
        return 0;
    }

    //checking condition if we have previously calculated same condition
    if(t[n][m] != -1){
        return t[n][m];
    }

    //choice diagram
    if( x[n-1] == y[m-1]){
        t[n][m] = 1+ lcs(x, y, n-1, m-1);
    }else{
        t[n][m] = max(lcs(x, y, n-1, m), lcs(x, y, n, m-1));
    }
    return t[n][m];
}

int main(){
    string x = "abcedgh";
    string y = "abedfhr";
    int n = x.size();
    int m = y.size();

    //initialization of global variable limits
    t.assign(n+1, vector<int>(m+1, -1));

    cout<< lcs(x, y, n, m);
    return 0;
}