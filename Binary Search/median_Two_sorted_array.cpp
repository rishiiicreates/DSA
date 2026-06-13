// * Purpose: Finds the median of two sorted arrays in O(log(min(M, N))) time.
// * Prerequisite: Both arrays must be independently sorted.

// CORE INTUITION (Binary Search on Partitioning):
// We need to divide both arrays into two halves (Left half and Right half) such that:
//   1. Total elements in Left half == Total elements in Right half.
//   2. Every element in Left half <= Every element in Right half.
// Instead of merging, we use binary search on the SMALLER array to find the perfect partition point. :3

// PARTITION VALIDATION LOGIC:
// Let partitionX be the cut in nums1, and partitionY be the cut in nums2.
// We look at the edge elements around the cuts:
//   * maxLeftX  = nums1[partitionX - 1] (or -infinity if empty)
//   * minRightX = nums1[partitionX]     (or +infinity if empty)
//   * maxLeftY  = nums2[partitionY - 1] (or -infinity if empty)
//   * minRightY = nums2[partitionY]     (or +infinity if empty)
//
// The partition is PERFECT if: (maxLeftX <= minRightY) && (maxLeftY <= minRightX)
//   a. If maxLeftX > minRightY -> We cut too far right in nums1. Move left (high = partitionX - 1).
//   b. If maxLeftY > minRightX -> We cut too far left in nums1. Move right (low = partitionX + 1).
// Once perfect, median is max(maxLeft) for odd total size, or average of max(maxLeft) and min(minRight) for even.

// COMPLEXITY:
// * Time Complexity: O(log(min(M, N))) - Binary search runs exclusively on the shorter array.
// * Space Complexity: O(1)             - Constant extra space used.


//problem statement;
//input: vector<int>& nums1, vector<int>& nums2
//output: double (median value)

//ex: nums1 = {1, 3}, nums2 = {2} -> Output: 2.0
//    nums1 = {1, 2}, nums2 = {3, 4} -> Output: 2.5

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
    // # Ensure nums1 is the smaller array to optimize binary search range !!
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int m = nums1.size();
    int n = nums2.size();
    int low = 0, high = m;

    while (low <= high) {
        int partitionX = low + (high - low) / 2;
        int partitionY = (m + n + 1) / 2 - partitionX;

        // Handling edge cases when partitions are at the absolute boundaries
        int maxLeftX  = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];

        int maxLeftY  = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];

        // Check if we found the correct partition
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            // If total elements are odd
            if ((m + n) % 2 != 0) {
                return max(maxLeftX, maxLeftY);
            }
            // If total elements are even
            return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
        }
        else if (maxLeftX > minRightY) {
            high = partitionX - 1; // Move left in nums1
        }
        else {
            low = partitionX + 1;  // Move right in nums1
        }
    }

    return 0.0; // (._.) #should never reach here if inputs are sorted properly
}


int main() {
    // Test Case 1: Even total length
    vector<int> nums1 = {1, 3, 8, 9};
    vector<int> nums2 = {7, 11, 18, 19, 21, 25};
    
    // Test Case 2: Odd total length
    vector<int> nums3 = {2, 3, 5, 8};
    vector<int> nums4 = {10, 12, 14, 16, 18, 20, 22};

    cout << "Median of test case 1: " << findMedianSortedArrays(nums1, nums2) << endl; // Expected: 10.0
    cout << "Median of test case 2: " << findMedianSortedArrays(nums3, nums4) << endl; // Expected: 12.0

    return 0;
}