//given: arr[], target sum;
// use + or - that arr[items] gives target sum
//output: combinations count

#include <iostream>
#include <vector>
using namespace std;

int targetsum(vector<int>& arr, int target){
    int len = arr.size();
    int sum = 0;
    for(int i = 0; i < len; i++){
        sum += arr[i];
    }

    if((sum+target) % 2 != 0 || target > sum){
        return 0;
    }
    int flagsum = (sum+target)/2;

    vector<vector<int>> t(len+1, vector<int>(flagsum+1, 0));
    for(int i = 0; i < len+1; i++){
        t[i][0] = 1;
    }

    for(int i = 1; i < len + 1; i++){
        for(int j = 1; j < flagsum+1; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[len][flagsum];
}

int main(){
    vector<int> arr{1,1,2,3};
    int sum = 1;
    int result = targetsum(arr, sum);
    cout<<result;
    return 0;
}

/*
 * Explanation:
 * This file solves the target sum problem where elements can be assigned a '+' or '-' sign. 
 * It is mathematically equivalent to counting subsets with a given difference, 
 * thus utilizing the same DP subset sum methodology.
 */