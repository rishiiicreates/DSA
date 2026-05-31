// # knapsack Recursive: 

// input=      arr[w]:     1   3   4   5
//             arr[v]:     1   4   5   7
//             Capacity: 7

#include <iostream>
#include <vector>
using namespace std;

int knapsack(const vector<int>& wt, const vector<int>& val, int W, int len){
    
    //base conditions (think of the smallet valid input)
    if(len==0 || W == 0){
        return 0;
    }

    // recursive function: for(input) -> recursion-> for(smaller_input) -> recursion -> for(more_smaller_input).......


    //choice diagram
    if (wt[len-1] <= W){
        return max((val[len-1] + knapsack(wt, val, W - wt[len-1], len - 1)), knapsack(wt, val, W, len - 1));
    }

    else if(wt[len-1] > W){
        return knapsack(wt, val, W, len-1);
    }
    return 0;
}

int main(){
    vector<int> wt { 1,3,4,5};
    vector<int> val { 1,4,5,7};

    int W = 7;
    cout<<knapsack(wt, val, W, wt.size() - 1);
    return 0;
}

