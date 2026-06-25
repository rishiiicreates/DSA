// finding maximum area that a barchart(histogram) can conver ( type of nearest smaller)

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int MAH(const vector<int>& arr) {
    int n = arr.size();
    stack<int> s;
    int max_area = 0;

    for(int i = 0; i < n; i++){
        int curr_length = (i==n) ? 0: arr[i];

        while(!s.empty() && arr[s.top()] >= curr_length){
            int height = arr[s.top()];
            s.pop();


            int width = s.empty() ? i : (i - s.top() - 1);

            max_area = max(max_area, width*height);
        }
        s.push(i);
    }
    return max_area;
}


int main() {
    vector<int> arr{6, 2, 5, 5, 5, 1, 6};
    cout << "Maximum Histogram Area: " << MAH(arr) << endl;
    return 0;
}

/*
 * Explanation:
 * This algorithm finds the maximum rectangular area possible in a given histogram where the largest rectangle can be formed by contiguous bars.
 * It uses a stack to keep track of the indices of the bars.
 * For every bar, we calculate the area with that bar as the smallest bar in the rectangle.
 * The stack stores the indices of the bars in an increasing order of their heights.
 * When we encounter a bar shorter than the bar at the top of the stack, we pop the top bar and calculate the area of the rectangle with the popped bar as the smallest bar.
 * The 'width' of this rectangle is determined by the current index `i` (as the right boundary) and the new top of the stack (as the left boundary).
 * This ensures an O(N) time complexity because every element is pushed and popped exactly once.
 */