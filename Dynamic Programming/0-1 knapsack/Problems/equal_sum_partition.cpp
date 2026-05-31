#include <iostream>
#include <vector>
using namespace std;

//problem statement:
//given: arr[int];
//output: true/false;
//goal: divide the arr in two to get equal sum


bool sumpart(vector<int>& arr){
    int len = arr.size();
    
    //checking running conditions
    long sum = 0;
    for(int i = 0; i < len; i++){
        sum += arr[i];
    }
    if(sum % 2 != 0){
        cout<<"Partition not possible";
        return false;
    }
    sum = sum/2;


    //initialization
    vector<vector<bool>> t(len+1, vector<bool>(sum+1, false));
    for(int i = 0; i < len+1; i++){
        t[i][0] = true;
    }

    for(int i = 1; i < len+1; i++){
        for(int j = 1; j < sum+1; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }

            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[len][sum];

}

int main(){
    vector<int> arr{ 1, 3, 4, 5, 6 ,7, 8, 9, 10};
    bool ans = sumpart(arr);
    cout<<ans;
    return 0;
}