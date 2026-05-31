#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minsubsetsum(vector<int>& arr){

    //initialization
    int len = arr.size();
    int sum = 0;
    for(int i = 0; i < len; i++){
        sum += arr.at(i);
    }

    //absolute minimum = s2 - s1 = (sum-s1) - s1 = sum - 2s1
    vector<vector<bool>> t( len + 1 , vector<bool>(sum/2+1, false));
    for(int i = 0; i < len+1; i++){
        t[i][0] = true;
    }

    for(int i = 1; i < len+1; i++){
        for(int j = 1; j < (sum/2)+1; j++){
            if(arr[i] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    int mn = 0;
    for(int i = sum/2; i >= 0; i--){
        if(t[len][i] == true){
            mn = i;
            break;
        }
    }
    return sum - 2*mn;
}

int main(){
    vector<int> arr{1,6,11,5};
}