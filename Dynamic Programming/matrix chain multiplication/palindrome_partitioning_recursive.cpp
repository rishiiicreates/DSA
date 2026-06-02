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