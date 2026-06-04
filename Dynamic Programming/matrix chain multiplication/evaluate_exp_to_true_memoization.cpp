#include <iostream>
#include <vector>
using namespace std;

// vector<vector<vector<int>>> t;

// int solve(const string& arr, int i, int j, bool wtf){
    
//     //checking if the answer is there in the dp
//     if(t[i][j][wtf] != -1) return t[i][j][wtf];

//     //base condition
//     if(i > j) return false;

//     if(i==j){
//         if(wtf == true) return (arr[i] == 'T') ? true : false;
//         else return (arr[i] == 'F') ? true : false;
//     }

//     int ans = 0;

//     for(int k = i+1; k < j; k+=2){
//         int lt = solve(arr, i, k - 1, true);
//         int lf = solve(arr, i, k - 1, false);
//         int rt = solve(arr, k + 1, j, true);
//         int rf = solve(arr, k + 1, j, false);

//         if(arr[k] == '&'){
//             if(wtf == true) ans += lt * rt;
//             else ans += (lf * rt) + (lt * rf) + (lf * rf);
//         }
//         else if(arr[k] == '|'){
//             if(wtf == true) ans += (lt * rt) + (lt * rf) + (lf * rt);
//             else ans += lf * rf;
//         }
//         else if(arr[k] == '^'){
//             if(wtf == true) ans += (lf * rt) + (lt * rf);
//             else ans += (lt * rt) + (lf * rf);
//         }
//     }
//     return t[i][j][wtf] = ans;
// }

// int main(){
//     string arr = "T|F&T^F|F";
//     int i = 0;
//     int j = arr.size() - 1;
//     t.assign(j+1, vector<vector<int>>(j+1, vector<int>(2, -1)));
//     cout << "Number of ways: " << solve(arr, i, j, true) << endl; 
//     return 0;
// }



//wihout 3D matrix: using map

#include <map>
#include <string>
//global declaration
map<string,int> mp;

int solve(const string& arr , int i, int j, bool wtf){
    //base condition
    if(i>j) return 0;

    if(i==j){
        if(wtf == true) return arr[i] == 'T' ? true : false;
        else return (arr[i] == 'F') ? true : false;
    }

    //checking if the key exist in the map

    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(wtf));

    if(mp.find(temp) != mp.end()){
        return mp[temp];
    }

    int ans = 0;

    //choice diagram

    for(int k = i+1; k < j; k+=2){
        int lt = solve(arr,i,k-1, true);
        int lf = solve(arr,i,k-1, false);
        int rt = solve(arr,k+1,j, true);
        int rf = solve(arr,k+1,j, false);

        if(arr[k] == '|') {
            if(wtf == true ) ans += lt*rf + rt*lf + rt*lt;
            else ans += lf*rf;
        }
        else if(arr[k] == '&') {
            if(wtf == true) ans += lt*rt;
            else ans += lt*rf + rt*lf + rf*lf;
        }

        else if(arr[k] == '^'){
            if (wtf == true) ans += lt*rf + rt*lf;
            else ans += lt*rt + lf*rf;
    
        }
    }   
    return mp[temp] = ans;

}

int main(){
    string arr = "T|F&T^F|F";
    int i = 0;
    int j = arr.size() - 1;
//    t.assign(j+1, vector<vector<int>>(j+1, vector<int>(2, -1)));
    cout << "Number of ways: " << solve(arr, i, j, true) << endl; 
    return 0;
}
