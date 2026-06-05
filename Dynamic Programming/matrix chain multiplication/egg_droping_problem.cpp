//flow: problem statement -> patter -> code variation

//input: eggs[int], floors[int]
//output: int[minimise the no. of attempt in worst case]

//task: threashold floor: after that floor, eggs start breaking and including threashold floor and floors below it, eggs dont break;
//find minimum no of attempt to find critical floor





#include <iostream>
using namespace std;

int solve(const int& e, const int& f){
    //base condition
    if(e <= 1 || f <= 1) return f;

    int ans = INT_MAX;

    for(int k = 1; k <= f; k++){

        int temp = max(solve(e-1, k-1), solve(e, f-k)) + 1;
        ans = min(temp, ans);
    }
    return ans;
}

int main(){
    int e,f;
    cout<< "Enter eggs and floors:";
    cin>>e>>f;
    cout<<"Minimum no of attempts:"<<solve(e,f);
    return 0;
}