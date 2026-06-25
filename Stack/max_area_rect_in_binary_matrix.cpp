#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int MAH(const vector<int>& arr){
    int n = arr.size();
    stack<int> s;
    int max_area = 0;

    for(int i = 0; i <= n; i++){
        int curr_length = (i==n) ? 0: arr[i];

        while(!s.empty() && arr[s.top()] >= curr_length){
            int height = arr[s.top()];
            s.pop();
            int width = (s.empty() ? i : (i - s.top() - 1));

            max_area = max(max_area, width*height);
        }
        s.push(i);
    }
    return max_area;
}


int maximalRectangle(vector<vector<int>>& matrix) {
   
    if(matrix.empty()) return 0;
    vector<int> histogram(matrix[0].size(), 0);
    int max_area = 0;

    for(int i = 0; i < matrix.size(); i++){
        for( int j = 0; j < matrix[0].size(); j++ ){
            if(matrix[i][j] == 0) histogram[j] = 0;
            else histogram[j] += 1; 
        }
        max_area = max(max_area, MAH(histogram));
    }
    return max_area;
}

int main(){
    vector<vector<int>> matrix ={
        { 0, 1, 1, 0},
        { 1, 1, 1, 1},
        { 1, 1, 1, 1},
        { 1, 1, 0, 0}
    };

    cout << "Maximum Area of Rectangle in Binary Matrix: " << maximalRectangle(matrix) << endl;
    return 0;
}

/*
 * Explanation:
 * This algorithm finds the maximum rectangular area of 1s in a 2D binary matrix.
 * It works by reducing the problem to multiple instances of the "Maximum Area Histogram" (MAH) problem.
 * The matrix is processed row by row. For each row, a 1D histogram array is maintained where the height represents the number of consecutive 1s in the current column ending at the current row. If a cell is 0, the corresponding histogram height becomes 0.
 * For each updated row, the MAH function is called to find the maximum rectangular area possible up to that row.
 * The overall maximum area found across all rows is returned. The time complexity is O(R * C), where R is the number of rows and C is the number of columns.
 */