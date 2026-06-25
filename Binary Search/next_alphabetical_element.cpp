//sorted array of alphabets
//find ceil of this arr[alphabets]
//if element present: if element is present, then also give ceil

#include <iostream>
#include <vector>
using namespace std;

char solve(const string& arr,const char& s){
    int len = arr.size();
    int left = 0;
    int right = len - 1;
    char ans = 0;

    while(left <= right){
        int mid = left + (right - left) / 2;

        if(arr[mid] == s){
            left = mid + 1;
        }
        else if(arr[mid] > s){
            ans = arr[mid];
            right = mid - 1;
        }else if(arr[mid] < s){
            left = mid + 1;
        }
    }
    return ans;
}

int main(){
    string arr = "abeg";
    char s = 'f';
    cout<<solve(arr,s);
}

/*
 * Explanation:
 * This file finds the "ceil" of a given character 's' in a sorted string/array of alphabetic characters.
 * The ceil is the smallest character strictly greater than 's'.
 * 
 * Algorithm steps:
 * 1. Initialize 'left' to 0 and 'right' to the string's last index.
 * 2. Use a variable 'ans' to store the potential ceil character.
 * 3. Loop while 'left <= right':
 *    - Calculate 'mid'.
 *    - If 'arr[mid] == s', the next alphabetical element must be to the right, so update 'left = mid + 1'.
 *    - If 'arr[mid] > s', 'arr[mid]' is a candidate for the answer. Store it in 'ans' and search in the left half ('right = mid - 1') to find a tighter, smaller candidate.
 *    - If 'arr[mid] < s', the ceil must lie in the right half, so update 'left = mid + 1'.
 * 4. Return 'ans'.
 */
