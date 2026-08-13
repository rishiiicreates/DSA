// flow-

// make inputj smaller.
// recursion: decision space
// recursive tree: soul of any recursion problem
// 2 step to solve any recusion problem



// 1) Make input smaller. But Why ??

// we really dont cut down input to make it smaller
// we take some decision -> input indepently gets smaller
// decision making: primary goal -> input automatically gets smaller


// 2) Recursive : decision space

// we take some decision;
// identification: choices + decisions


// 3) recursive tree: very important

// if we'ved designed a recursive tree, then coding is cakewalk




//===============================EXAMPLE================================
/*
THE SUBSET PROBLEM (INCLUSION-EXCLUSION PRINCIPLE)

The algorithm builds subsets by making a binary decision for each element: 
either we "Take" it or we "Leave" it. 

We use a pointer (index) to move from left to right through the set. Once 
the pointer reaches the end, a valid subset is finished.

                     [ Start: {} ]
                      /         \
              Take 1 /           \ Leave 1
                    /             \
                {1}                 {}
               /   \               /   \
       Take 2 /     \ Leave 2     /     \
             /       \           /       \
         {1, 2}     {1}        {2}       {}   ... and so on.

*/

// STEP 1: THE BASE CASE (The Stop Sign)
// If the current index equals the total size of the input elements:
//   - We have made a decision for every single item.
//   - The current subset is now complete. Save it / Print it.
//   - Return (Stop and go back to explore other branches).

// STEP 2: BRANCH 1 - INCLUDE THE ELEMENT (Take It)
//   - Add the element at the current index to our temporary subset list.
//   - Move to the next index by calling the function again (Index + 1).

// STEP 3: BRANCH 2 - EXCLUDE THE ELEMENT (Leave It / Backtrack)
//   - Remove the element we just added from our temporary subset list.
//   # Note: This cleanup is mandatory to reset the state. (._.)
//   - Move to the next index by calling the function again (Index + 1).


//   TWO MAIN STEPS TO SOLVE A RECURSIION PROBLEM ARE:

//   Step 1) Design a recursive Tree
//   Step 2) apply the code to the tree


// recursion is very importance

// example: arr/string + tree + graph + heap + stack ..........
// recursion itself is a ds: like DP + backtracking + DNC

// In this portion: we'll only study recursion question not any addition of other DS and algos.


// Questions:

// -> Input - Output Methods

// 1) Print (1 to n)/(n to 1)
// 2) sort an array
// 3) delete middle element in a stack
// 4) remove duplicate from a string
// 5) count the no of occurance
// 6) subset
// 7) permutation a)spaces b)case change and many more
// 8) josephus problem / execuition in circle 
// 9) linked list


// -> Extended Input-Output Medthod

// 1) Binary string (no of 1's > no of 0's)
// 2) generate balance parenthesis
