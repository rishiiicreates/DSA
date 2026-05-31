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