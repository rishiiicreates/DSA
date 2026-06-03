#include <iostream>
#include <vector>
using namespace std;

vector<vector<vector<int>>> t;

int solve(const string& arr, int i, int j, bool wtf){
    
    //checking if the answer is there in the dp
    if(t[i][j][wtf] != -1) return t[i][j][wtf];

    //base condition
    if(i > j) return false;

    if(i==j){
        if(wtf == true) return (arr[i] == 'T') ? true : false;
        else return (arr[i] == 'F') ? true : false;
    }

    int ans = 0;

    for(int k = i+1; k < j; k+=2){
        int lt = solve(arr, i, k - 1, true);
        int lf = solve(arr, i, k - 1, false);
        int rt = solve(arr, k + 1, j, true);
        int rf = solve(arr, k + 1, j, false);

        if(arr[k] == '&'){
            if(wtf == true) ans += lt * rt;
            else ans += (lf * rt) + (lt * rf) + (lf * rf);
        }
        else if(arr[k] == '|'){
            if(wtf == true) ans += (lt * rt) + (lt * rf) + (lf * rt);
            else ans += lf * rf;
        }
        else if(arr[k] == '^'){
            if(wtf == true) ans += (lf * rt) + (lt * rf);
            else ans += (lt * rt) + (lf * rf);
        }
    }
    return t[i][j][wtf] = ans;
}

int main(){
    string arr = "T|F&T^F|F";
    int i = 0;
    int j = arr.size() - 1;
    t.assign(j+1, vector<vector<int>>(j+1, vector<int>(2, -1)));
    cout << "Number of ways: " << solve(arr, i, j, true) << endl; 
    return 0;
}