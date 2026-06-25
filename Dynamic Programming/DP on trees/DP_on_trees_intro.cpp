
//flow:

//-> general syntax
//-> how dp can be applied on tree(identification)

//Questions:
//->Diameter of a Binary Tree
//->Maximum path sum form any node to any
//->Maximum path sum from leaf to leafs
//->Diameter of N-array Tree

//Identification is it a dp tree question ??
//O(n) - complexity
//traversing tree and zevery node


//Diameter = longest path between two leafs

//General Syntax:

//recursive function in tree mainly contains:

// r_tyoe fn_name(input){

//     step-1: base condition;

//     step-2: hypothesis ( never question hypothesis);

//     step-3induction;
// }


//General code:
#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int data){
        val = data;
        right = nullptr;
        left = nullptr;
    }
};

int solve(Node* root, int& result){ // this result constain the main answer

    //base condition:
    if(root == nullptr) return 0; // can change according to the questions

    //hypothesis:
    int l = solve(root->left, result);
    int r = solve(root->right, result);

    //induction:
    int temp = 1 + max(l,r);
    int ans = max(temp, relation); //relation define if the node is root or not
    result = max(ans,result);

    return result;
}

int main(){
    int result = INT_MIN;
    solve(input, result);
    return result;
}

/*
 * Explanation:
 * This file serves as an introduction to Dynamic Programming on Trees.
 * It outlines the general recursive syntax used for these problems which usually involves three steps:
 * 1. Base condition (often checking for null nodes).
 * 2. Hypothesis (recursive calls to left and right children).
 * 3. Induction (using the child results to compute the local optimal and update a global 'result' reference).
 * The template shows how a global maximum or minimum is maintained while returning a value to the parent node.
 */