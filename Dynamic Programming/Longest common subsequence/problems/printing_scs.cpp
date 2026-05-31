//printing shortest common supersequence

#include <iostream>
#include <vector>
using namespace std;

string printscs(const string& x, const string& y){
    int n = x.size();
    int m = y.size();

    vector<vector<int>> t(n+1, vector<int>(m+1, 0));

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
            if(x[i-1] == y[j-1]){
                t[i][j] = t[i-1][j-1] + 1;
            }else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    string ans = "";

    while(n != 0 && m != 0){
        if(x[n-1] == y[m-1]){
            ans.push_back(x[n-1]);
            n--;
            m--;
        }else{
            if(t[n-1][m] > t[n][m-1]){
                ans.push_back(x[n-1]);
                n--;
            }else{
                ans.push_back(y[m-1]);
                m--;
            }
        }
    }
    while( n > 0 ){
        ans.push_back(x[n-1]);
        n--;
    }
    while( m > 0 ){
        ans.push_back(y[m-1]);
        m--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string x = "abcdaf";
    string y = "acbcf";
    string ans = printscs(x, y);
    cout<< ans;
    return 0;
}