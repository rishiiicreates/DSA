/*
KTH SYMBOL IN GRAMMAR (Theory)

Problem:
Row 1 = "0"

To generate next row:
0 -> 01
1 -> 10

Rows:
n=1 -> 0
n=2 -> 01
n=3 -> 0110
n=4 -> 01101001

Question:
Find the k-th symbol in n-th row.

--------------------------------------------------

Brute Force Idea:
- Generate each row as a string
- Return k-th character

Problem:
Row size doubles every time.

Length of row n:
2^(n-1)

So generating full row is expensive for large n.

--------------------------------------------------

Core Observation:
Each row consists of 2 halves:

1. Left half  = previous row
2. Right half = inverse of previous row
   (0 becomes 1, 1 becomes 0)

Example:
Row 4 = 0110 | 1001
         left   right

Left  = row 3
Right = inverse(row 3)

This is the main recursive pattern.

--------------------------------------------------

Recursive Logic:

To find symbol at (n, k):

1. Calculate row length:
   length = 2^(n-1)

2. Calculate half:
   half = length / 2

Case 1:
If k <= half
Answer is same as:
f(n-1, k)

Reason:
First half is exactly previous row.

Case 2:
If k > half
Answer is inverse of:
f(n-1, k-half)

Reason:
Second half is inverted previous row.

--------------------------------------------------

Base Case:
Row 1 contains only one symbol:

f(1,1) = 0

--------------------------------------------------

Important Intuition:
Every time recursion moves into RIGHT half,
a flip happens:

0 -> 1
1 -> 0

So:
- Even number of flips => 0
- Odd number of flips  => 1

--------------------------------------------------

Concepts Tested:
- Recursion
- Divide and Conquer
- Pattern Recognition
- Binary Tree Thinking
- Bit Manipulation (advanced)

--------------------------------------------------

Common Mistakes:
1. Building full string
2. Off-by-one indexing
3. Wrong half calculation
4. Forgetting inversion in right half

Summary:
This is NOT a string problem.
It is a recursive pattern problem.
*/



#include <iostream>
#include <math.h>
using namespace std;

bool solve(int n, int k){

    //base condition
    if(n==1 || k==1) return 0;

    //induction
    int mid = pow(2,n-1) / 2;

    //hypothesis
    if(k <= mid) return solve(n-1, k);
    else return solve(n-1, k-mid);

}

int main() {
    int n = 4;
    int k = 5;

    cout << "K = " << k << " : " << solve(n, k) << endl;
    
    return 0;
}

/*
 * Explanation:
 * This algorithm recursively finds the k-th symbol in the n-th row of a grammar sequence.
 * 1. Base Condition: If n = 1 (first row) or k = 1 (first symbol in any row), the value is 0.
 * 2. Induction/Hypothesis: The problem exhibits a pattern where the first half of a row is 
 *    identical to the previous row, and the second half is its inverse (though the inversion 
 *    is not explicitly implemented in this code snippet). We find the midpoint of the row.
 *    If 'k' is in the left half, we recursively look for the k-th element in row 'n-1'.
 *    If 'k' is in the right half, we recursively look for the (k-mid)-th element in row 'n-1'.
 */
