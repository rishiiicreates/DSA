
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


int solve(node* root, int& result){ // this result constain the main answer

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
    solve(input);
    return result;
}