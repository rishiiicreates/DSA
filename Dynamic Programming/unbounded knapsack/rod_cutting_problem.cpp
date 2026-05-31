//problem statement -> 0-1 or unbounded -> figuring out the concept use -> code variation;
//given: rod length; arr[price]( sometime arr[length] given or we take arr[price] indicese as length )
//task: cutting the rod in proportion; without restrictions. get the maximum profit

//same code of unbounded knapsack (bwaahahahha; Fuck you DSA)

#include <iostream>
#include <vector>
using namespace std;

int rodcut(vector<int>& arr, vector<int>& length, int capacity){
    int len = arr.size();

    vector<vector<int>> t(len + 1, vector<int>(capacity + 1, 0));

    for(int i = 1; i < len + 1; i++){
        for(int j = 1; j < capacity + 1; j++){
            if(arr[i-1] <= j){
                t[i][j] = max(length[i-1] + t[i][j-arr[i-1]], t[i-1][j]);
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[len][capacity];
}

int main(){
    vector<int> arr{1,2,3};
    vector<int> len{1,2,3};
    int sum = 5;
    cout<< rodcut(arr, len, sum);
    return 0;
}
