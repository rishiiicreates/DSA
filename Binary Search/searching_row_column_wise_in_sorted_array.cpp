// * Purpose: Finds a target value in a 2D matrix in O(M + N) time.
// * Prerequisite: Matrix must be sorted ROW-WISE and COLUMN-WISE independently.

// CORE INTUITION (Top-Right Corner Property):
// The element at matrix[0][cols - 1] is unique because it is:
//   1. The MAXIMUM element of its current row.
//   2. The MINIMUM element of its current column.
// This provides an unambiguous direction to move after every comparison. :3

// TRAVERSAL LOGIC:
// 1. Initialize pointers at the top-right corner: row = 0, col = cols - 1.
// 2. Loop while inside matrix boundaries (row < total_rows && col >= 0):
//    a. If matrix[row][col] == target -> Return true/coordinates.
//    b. If matrix[row][col] > target  -> Eliminate current column (col-- / move left).
//    c. If matrix[row][col] < target  -> Eliminate current row (row++ / move down).
// 3. If loop ends without a match, the target does not exist. (._.) #search goes out of bound !!

// COMPLEXITY:
// * Time Complexity: O(M + N) - Shaves off one row or column per step.
// * Space Complexity: O(1)   - Only uses two pointer variables.


//problem statement;
//input: arr[2D], int key
//output: index of key

//ex: vector<vector<int>> arr {  
    // {10,  20,  30,  40},
    // {15,  25,  35,  45},
    // {27,  29,  37,  49},
    // {32,  33,  39,  50},
//}

//approach: start travesing from top right corner; that i = 0 and j = m-1 for size of matrix (m x n)
//          we take that right corner as mid for our binary search


#include <iostream>
#include <vector>
using namespace std;

pair<int,int> solve(const vector<vector<int>>& arr,const int& k){
    int rows = arr.size();
    int cols = arr[0].size();
    int i = 0;
    int j = rows - 1;

    while( i >= 0 && i < rows && j >= 0 && j < cols){
        if(arr[i][j] == k) return {i,j};
        else if(arr[i][j] > k) j--;
        else if(arr[i][j] < k) i++;
    }
    return{-1,-1};
}

int main(){
    vector<vector<int>> arr {  
        {10,  20,  30,  40},
        {15,  25,  35,  45},
        {27,  29,  37,  49},
        {32,  33,  39,  50},
    };
    int k = 35;
    pair<int,int> ans = solve(arr,k);
    cout<<"row:"<< ans.first+1 <<"    "<<"columns:"<<ans.second+1;
    return 0;
}