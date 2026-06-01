//problem statement: similar to min delete to palindrome
//input: arr[string]
//output: no of insertion to make palindrome;
//ex: s: "aebcbda" -> (adebcbeda) -> two insetions ("d and e")

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int min_d_palindrome(const string& s){
    int len = s.size();
    string k = s;
    reverse(k.begin(), k.end());

    vector<vector<int>> t(len + 1, vector<int>(len + 1, 0));

    // for example( to find min delete to make palindrome of : " aebcbda" = x; that means x are extra element
    // that are to the string; to make it palindrome, we need to add the same element. So no deletion to make
    // palindrome = deletion to make palindrome)

    for(int i = 1; i < len + 1; i++){
        for(int j = 1; j < len + 1; j++){
            if ( s[i-1] == k[j-1]){
                t[i][j] = t[i-1][j-1] + 1;
            }
            else{
                t[i][j] = max(t[i-1][j] , t[i][j-1]);
            }
        }
    }
    return(len - t[len][len]);
}

int main(){
    string s = "aebcbda";
    cout<<min_d_palindrome(s);
    return 0;
}