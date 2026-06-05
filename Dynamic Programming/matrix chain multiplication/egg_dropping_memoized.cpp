#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> t;

int solve(const int& e, const int& f){

    if(t[e][f] != -1) return t[e][f];

    if( e <= 1 || f <= 1) return f;

    int ans = INT_MAX;

    for(int i = 1; i < f; i++){
        int temp = max(solve(e-1,i-1), solve(e,f-i)) + 1;
        ans = min(ans, temp);
    }
    return t[e][f] = ans;
}

int main(){
    int e,f;
    cout<< "Enter eggs and floors:";
    cin>>e>>f;
    t.assign(e+1,vector<int>(f+1, -1));
    cout<<"Minimum no of attempts:"<<solve(e,f);
    return 0;
}