//flow: problem statement -> how to identify -> how to approach -> how to breakdown -> base condition -> code variation
//input: two string: arr[string1], arr[string2]
//output: if one can be rearranged to form second one;
//asks: to create a binary tree;
//output: boolean output: T/F;

//constrains: create binary tree, no empty child, non leaf node -> swapping (0 or more) -> scrambled string or not ??

//approach: ex: str = "great"
//swap non leaf node: g, r, e, a, t;

//on dividing the scrambled string on two parts -> either going to swap on not.
// gr|eat -> ate|gr : we check recursively, not equally.

//in a nutshell: two cases -> either scrambled or not {either swapped or not} -> checking accordingly if swapped or not;
//basically: a.last = b.first and b.last = a.first is swapped and if not then -> a.first = b.first and a.last = b.last

#include <iostream>
using namespace std;
#include <string>

bool solve(const string& a, const string& b){
    int n = a.length();

    //base condition
    if(a.empty() && b.empty()) return false;
    if(a.compare(b)==0) return true;
    
    bool flag = false;
    
    for(int i = 1; i < n; i++){

        if(solve(a.substr(0,i),b.substr(n-i,i))== true && solve(a.substr(i,n-i),b.substr(0,n-i))== true){//first = second condition
            flag = true;
        }

        if(solve(a.substr(0,i), b.substr(0,i)) == true && solve(a.substr(i,n-i), b.substr(i,n-i)) == true){//first = first condition
            flag = true;
        }
    }
    return flag;
}

int main(){
    string a;
    string b;
    cin>>a>>b;
    if(a.length() != b.length()) return 1;
    if(a.empty() && b.empty()) return 1;
    int ans = solve(a,b);
    cout<< ((ans > 0) ? "True" : "False");
    return 0;
}

/*
 * Explanation:
 * This file implements a recursive solution to the Scrambled String problem. It determines whether one string can be transformed into another by representing it as a binary tree and allowing the swapping of non-leaf nodes. The `solve` function checks base cases (equality or emptiness) and then tries splitting the strings at every possible length `i`. For each split, it recursively checks two scenarios: 1) the children of the current node were swapped (comparing left of `a` with right of `b`, and right of `a` with left of `b`), or 2) the children were not swapped (comparing left of `a` with left of `b`, and right of `a` with right of `b`).
 */