//sorted array of alphabets
//find ceil of this arr[alphabets]

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

        if(arr[mid] == s) return arr[mid];
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
    return 0;
}


