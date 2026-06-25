// # one of the best question for binary search !!



// * Purpose: Finds the minimum possible value of the maximum pages allocated to a student.
// * Prerequisite: The pages array must be sorted (or sorted manually before processing).

// CORE INTUITION (Binary Search on Answer Space):
// Sorted array not required.
// Instead of searching through the array indices, we search through the POSSIBLE ANSWER RANGE.
//   * Minimum possible answer (low)  = Maximum element in the array (since at least one student must take it).
//   * Maximum possible answer (high) = Sum of all elements in the array (if only 1 student takes everything).
// We pick a mid-point `mid` and check if it is a valid maximum page allocation.

// VALIDATION LOGIC (`isPossible` function):
// 1. Iterate through the books and sequentially assign pages to the current student.
// 2. If adding the next book exceeds `mid`:
//    a. Allocate the book to the NEXT student.
//    b. Reset the current student's page counter to this book's pages.
// 3. If the total number of students required exceeds the allowed limit `M`, then `mid` is too small.
//    -> Move right (low = mid + 1).
// 4. If the assignment succeeds within `M` students, `mid` is a potential answer. 
//    -> Record it and try to find a smaller maximum by moving left (high = mid - 1).

// COMPLEXITY:
// * Time Complexity: O(N * log(Sum - Max)) - Binary search runs over the answer range, validating in O(N).
// * Space Complexity: O(1)                - Purely iterative pointer manipulation.



//problem statement;
//input: vector<int>& pages, int students
//output: int (the minimized maximum pages)


//ex: pages = {12, 34, 67, 90}, students = 2 -> Output: 113
//    Allocation: Student 1 gets {12, 34, 67} (113 pages), Student 2 gets {90} (90 pages). Max is 113.

// # Edge Case: If books < students, it is impossible to allocate at least one book to everyone !! (._.)



#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool isValid(const vector<int>& arr,const int& len,const int& students,const int& mid){
    int nostudent = 1;
    int sum = 0;
    for(int i = 0; i < len; i++){
        sum += arr[i];
        if(sum > mid){
            nostudent++;
            sum = arr[i];
        }if(nostudent > students){
        return false;
        }
    }
    return true;
}

int solve(const vector<int>& arr, const int& students){
    int len = arr.size();
    if(len < students) return -1;
    
    int left = *max_element(arr.begin(),arr.end());
    int right = accumulate(arr.begin(),arr.end(),0);

    int result = -1;

    while(left <= right){
        int mid = left + (right - left)/2;
        if(isValid(arr,len,students,mid) == true){
            result = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return result;
}


int main() {
    vector<int> pages = {10,20,30,40};
    int students = 2;

    int ans = solve(pages, students);
    cout << "Minimum possible maximum pages = " << ans << '\n'; // expected: 113

}

/*
 * Explanation:
 * This file solves the "Allocate Minimum Number of Pages" problem using binary search on the answer space.
 * 
 * Algorithm steps:
 * 1. The search space for the answer (maximum pages assigned to a student) ranges from the maximum single book's pages ('left = max(arr)') to the sum of all pages ('right = sum(arr)').
 * 2. Binary search within this range '[left, right]'. For a candidate 'mid', a helper function 'isValid' checks if books can be allocated to 'students' students such that no student reads more than 'mid' pages.
 * 3. Inside 'isValid':
 *    - Iterate through books, greedily assigning them to the current student.
 *    - If adding a book exceeds 'mid', assign it to a new student and increment the student count.
 *    - If the student count exceeds the allowed number 'students', 'mid' is not a valid allocation (return false).
 * 4. If 'isValid' returns true for 'mid', it means 'mid' is a potential minimum maximum pages value. Store it as 'result' and attempt to find a smaller valid maximum by searching the left half ('right = mid - 1').
 * 5. If false, the maximum limit 'mid' is too strict, so search the right half ('left = mid + 1').
 */