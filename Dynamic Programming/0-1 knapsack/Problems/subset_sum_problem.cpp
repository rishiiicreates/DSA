#include <iostream>
#include <vector>
using namespace std;

bool knapsack(vector<int>& arr, int sum){
    int len = arr.size(); 
    
    //initialization:
    vector<vector<bool>> t(len + 1, vector<bool>(sum + 1, false));
    for(int i = 0; i < len + 1; i++){
        t[i][0] = true;
    }

    //choice diagram
    for(int i = 1; i < len+1; i++){
        for(int j = 1; j < sum+1; j++){

            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }

            else{
                t[i][j] = t[i-1][j];
            }

        }
    }
    return t[len][sum];
}


int main(){
    vector<int> arr { 1, 4, 7, 12};
    int sum = 11;
    bool ans = knapsack(arr, sum);
    cout << (ans > 0 ? "true" : "false");
    return 0;
}

/*
 * Explanation:
 * This file checks if there exists a subset within the array that adds up 
 * to a specific target sum. It builds a boolean DP matrix returning true if 
 * the target sum can be achieved by including or excluding items.
 */