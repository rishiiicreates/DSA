//Given: arr[], int diff;
//Output: count of subsets with given difference

#include <iostream>
#include <vector>
using namespace std;

int nosubset(vector<int>& arr, int diff){
    int len = arr.size();
    int sum = 0;
    for(int i = 0; i < len; i++){
        sum += arr[i];
    }

    if((sum+diff) % 2 != 0 || diff > sum) return 0;
    int flagsum = (diff+sum)/2;

    vector<vector<int>> t(len+1, vector<int>(flagsum+1, 0));
    for(int i = 0; i < len + 1; i++){
        t[i][0] = 1;
    }

    for(int i = 1; i < len+1; i++){
        for(int j = 1; j < flagsum+1; j++){
            if(arr[i-1]<= j){
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            }else{
              t[i][j] = t[i-1][j];
            }
        }
    }
    return t[len][flagsum];
}


int main(){
    vector<int> arr{1,1,2,3};
    int ans = nosubset(arr, 1);
    cout<<ans;
    return 0;
}

/*
 * Explanation:
 * This file finds the number of subsets with a given difference. It translates 
 * the problem into finding the count of subsets with a specific target sum using 
 * mathematical deduction, based on the 0-1 knapsack paradigm.
 */