//problem statement:
//input: string
//task: divide to make palindrome
//output: no of partition ( worst case: string.size() - 1)

 

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

int solve(const string& arr, int i, int j){
    
    //base condition
    if ( i >= j) return 0; //because i == j can exist, [0] ; on i > j -> invalid input, 1 char string = 0 partition needed; already a plaindrome
    // but for NULL string -> we can divide it so return 0;

    if( palindrome(arr ,i,j)==1){
        return 0;
    }

    int mn = arr.length() - 1;

    for(int k  = i; k < j; k++){
        int temp = solve(arr, i, k) + solve(arr, k+1, j) + 1; // adding 1 because c3 = 1 (atleast 1 sepration)

        mn = min(mn, temp);
    }
    return mn;

}


int main(){
    // scheme: k = i to k = j-1 -> fn(i to k) and fn(k+1 to j)
    //         k = i+1 to k = j -> fn(i to k-1) and fn(k to j) 
    string arr = "abcba";
    int i = 0;
    int j = arr.size() - 1;
    cout<<solve(arr,i,j);
    return 0;
}

/*
 * Explanation:
 * This file implements the Palindrome Partitioning problem using a pure recursive approach. The goal is to find the minimum number of partitions (cuts) required such that every resulting substring is a palindrome. The `solve` function checks if the current substring from `i` to `j` is already a palindrome; if so, it returns 0 cuts. Otherwise, it tries all possible split points `k` between `i` and `j-1`, recursively finding the cuts needed for the left and right parts, and adds 1 for the current cut, keeping track of the minimum total cuts.
 */