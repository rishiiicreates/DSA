// we'll learn new method -> BASE CONDITION - HYPOTHESIS - INDUCTION

//flow: methods to think for a recursive problem
//      why making I/P smaller is so popular/important
//      printing 1 to N




//approch to solve recursive problem:

//1: Create a recursive tree (Decision)
//2: Base Condition - Induction - Hypothesis
//3: Choice Diagram



// THE HYPOTHESIS:

// 1. CORE CONCEPT
// --------------------------------------------------------------------------------
// The Recursive Hypothesis (also known as the Inductive Hypothesis) is the 
// explicit assumption that your recursive function already works perfectly for any 
// smaller sub-problem. 

// When writing a recursive function, you must completely resist the urge to mentally 
// trace the code deep down into subsequent hidden steps. Instead, you design the 
// logic under the firm belief that the smaller problem will return the absolute 
// correct result automatically.


// 2. THE 3-STEP RECURSIVE ARCHITECTURE
// --------------------------------------------------------------------------------
// Every standard recursive design relies on this precise sequence:

//    Step 1: Base Case
//    └── The absolute smallest, trivial version of the problem.
//        └── Resolved instantly without further recursion (e.g., Size = 0 or 1).

//    Step 2: Recursive Hypothesis 
//    └── The structural assumption.
//        └── You boldly declare: "My function correctly solves the problem for (N - 1)."

//    Step 3: Induction Step
//    └── The bridging logic.
//        └── You take the trusted result from Step 2, apply your current layer of 
//            work for element (N), and return the final combined answer.


// 3. REAL-WORLD ANALOGY: THE STAIRCASE PROBLEM
// --------------------------------------------------------------------------------
// Imagine calculating the total distance to the bottom of a 100-step staircase:

// * The Base Case: 
//   If you are on step 0, distance is 0. No calculation needed.

// * The Hypothesis: 
//   You look down at a friend standing on step 99. You completely trust that if 
//   you ask them "how many steps to the bottom?", they will give you the perfect 
//   mathematical answer (99). You don't try to calculate how they figured it out.

// * The Induction Step: 
//   You take their trusted answer (99) and perform your own single unit of work 
//   by adding your current step (+1) to it. Total = 100.


// # NOTE: THE GOLDEN RULE OF RECURSIVE DEBUGGING
// Trying to visualize the entire execution stack collapsing inside your head 
// is a fast track to absolute mental chaos. (._.) 

// Break the problem into a trusted smaller state, apply the current step's logic, 
// and let the C++ compiler handle the heavy lifting.

#include <iostream>
using namespace std;

void solve(int k){

    //base condition:
    if(k <= 0) return;
    
    //induction
    cout << k << "  ";
    
    //hypothesis
    solve(k-1);
}

int main(){
    int k = 10;
    solve(k);
    return 0;
}