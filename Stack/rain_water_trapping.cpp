

#include <iostream>
#include <vector>
using namespace std;

int trap(const vector<int>& arr){
    int n = arr.size();
    int mxl[n];
    int mxr[n];
    int area = 0;

    mxl[0] = arr[0];
    for(int i = 1; i < n; i++){
        mxl[i] = max(mxl[i-1], arr[i]);
    }

    mxr[n-1] = arr[n-1];
    for(int i = n-2; i >=0; i--){
        mxr[i] = max(mxr[i+1], arr[i]);
    }

    int water[n];
    for(int i = 0; i < n; i++){
        water[i] = min(mxl[i],mxr[i]) - arr[i];
    }

    for(int i = 0; i< n; i++){
        area += water[i];
    }
    return area;
}

int main() {
    vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped Water: " << trap(height) << endl;
    return 0;
}

/*
 * Explanation:
 * This algorithm calculates the amount of rainwater that can be trapped between the bars of an elevation map.
 * It uses two auxiliary arrays, `mxl` (maximum to the left) and `mxr` (maximum to the right), to precompute the highest bar to the left and right of every index respectively.
 * The amount of water trapped above any bar `i` is determined by `min(mxl[i], mxr[i]) - arr[i]`.
 * It iterates through the array to populate the prefix max array (`mxl`), and then iterates backwards to populate the suffix max array (`mxr`).
 * Finally, it calculates the water trapped at each index and sums it up, resulting in an O(N) time complexity and O(N) space complexity.
 */