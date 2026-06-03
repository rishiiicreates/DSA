//recursive approach
//Input: arr[string]
//string contains {T, F, &, |, ^} with T - F and operators every alternating T/F (loop ->k = i+1; k < j-1 k += 2)
//task: find ways get to evolute true
//ex: input: string s = "T|F&T^F"
//    output: no of ways to get to true by dividing into two parts with an operator in middle -> {(T) | (F&T^F)}

//looping through i[0] to j[arr.size()-1];
//base condition: if (i > j) return false;

#include <iostream>
#include <vector>
using namespace std;

int solve(const string& arr, int i, int j, bool wtf){
    // Base case 1: Empty string segment
    if(i > j) return 0;

    // Base case 2: Single character (must be 'T' or 'F')
    if(i == j){
        if(wtf == true) return (arr[i] == 'T') ? true : false;
        else return (arr[i] == 'F') ? true : false;
    }

    int ans = 0;

    // k loops through the operators, which are at odd indices
    for(int k = i + 1; k < j; k += 2){
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
    return ans;
}

int main(){
    string arr = "T|F&T^F";
    int i = 0;
    int j = arr.size() - 1;
    // We want the number of ways to evaluate to true
    cout << "Number of ways: " << solve(arr, i, j, true) << endl; 
    return 0;
}