//input: - binary tree
//output:- largest different between two leaf node ( find the no of nodes including largest different leaf node)

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int solve(Node* root, int& result){
    //base condition

    if(root == nullptr) return 0;

    int l = solve(root->left, result);
    int r = solve(root->right,result);

    int temp = max(l,r) + 1;
    int ans = max(temp, 1 + l + r);
    result = max(result, ans);

    return temp;
}


int main() {
  
        //       1
        //      / \
        //     2   3
        //    / \
        //   4   5

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int diameter = 0; // This will hold our final answer
    

    solve(root, diameter);

    cout << "The diameter of the binary tree (number of nodes) is: " << diameter << endl;
    return 0;
}

/*
 * Explanation:
 * This file implements an algorithm to find the diameter of a binary tree using Dynamic Programming on Trees.
 * The diameter is the longest path between any two leaf nodes, and here it is measured by the number of nodes.
 * The `solve` function returns the longest path extending from the current node down to a leaf (max(l, r) + 1).
 * Meanwhile, it updates a reference variable `result` with the maximum diameter found so far,
 * which is the sum of the longest paths from both the left and right children through the current node (l + r + 1).
 */
