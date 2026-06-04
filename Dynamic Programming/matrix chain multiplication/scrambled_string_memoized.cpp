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
