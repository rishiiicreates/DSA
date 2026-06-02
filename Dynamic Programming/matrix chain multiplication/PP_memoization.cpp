#include <iostream>
#include <vector>
using namespace std;

int palindrome(const string& arr, int i, int j){
    while(i<j){
        if(arr[i] != arr[j]) return 0;
        i++;
        j--;
    }
    return 1;
}

vector<vector<int>> t;

int solve(const string& arr, int i, int j){
    
    if(t[i][j] != -1) return 0;
    
    //base condition
    if(i >= j) return 0;

    if(palindrome(arr,i,j) == 1) return 0;

    int mn = j;

    //choice diagram
    for(int k = i; k < j; k++){
        int temp = solve(arr,i,k) + solve (arr,k+1,j) + 1;

        mn = min(temp, mn);
    }
    return t[i][j] = mn;
}
int main(){
    // scheme: k = i to k = j-1 -> fn(i to k) and fn(k+1 to j)
    //         k = i+1 to k = j -> fn(i to k-1) and fn(k to j) 
    string arr = "abcba";
    int i = 0;
    int j = arr.size() - 1;
    t.assign(j+1, vector(j+1, -1));
    cout<<solve(arr,i,j);
    return 0;
}