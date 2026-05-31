//input: arr[x] =  a b c d g h
//       arr[y] =  a b e d f h r

//output: longest common subsequence -> length of { a, b, d, h} ( intersection of arr[x] and arr[y]) # remember: longest common subsequence, 
// can be discontinuous

//recursive approach:

#include <iostream>
using namespace std;

int lcs(const string& x, const string& y, int n, int m){
    //to make recursive -> call at smaller value then previous. i.e. = for(x,y) -> for(x-1, y-1)
    //base condition: think of the smallest valid input
    if(n==0 || m==0){
        return 0;
    }

    //choice diagram
    // if last elements are matching -> n-1 , m-1;
    // if not matching -> max((n-1, m) + (n, m - 1));
    // longset common -> max() 

    if ( x[n-1] == y[m-1]){
        return 1 + lcs(x, y, n-1, m-1);
    }
    else{
        return max(lcs(x, y, n-1, m), lcs(x, y, n, m-1));
    }
}

int main(){
    string x = "abcedgh";
    string y = "abedfhr";
    int n = x.size();
    int m = y.size();
    cout<< lcs(x, y, n, m);
    return 0;
}