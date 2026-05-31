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