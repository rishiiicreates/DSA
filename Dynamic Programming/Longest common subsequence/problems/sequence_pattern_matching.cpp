//problem statement: string a is subseq of b or not  
//Given: arr[string1], arr[string2]
//output: bool value

#include <iostream>
#include <vector>
using namespace std;

bool spm(const string& x, const string& y){
    int n = x.size();
    int m = y.size();

    vector<vector<int>> t(n+1, vector<int>(m+1, 0));

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
            if(x[i-1]==y[j-1]){
                t[i][j] = t[i-1][j-1] + 1;
            }
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }

    if(n==t[n][m]) return true;
    return false;
}

int main(){
    string s = "axyx";
    string k = "adxcpy";
    cout<< (spm(s,k) > 0 ? "True" : "False");
    return 0;
}