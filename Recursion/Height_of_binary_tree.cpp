//problem statement: find of heigh of binary tree

#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int data){
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

int height(Node* root){

    // base condition
    if (root == nullptr) return 0;

    // hypothesis
    int l = height(root->left);
    int r = height(root->right);

    // induction
    return max(l, r) + 1;
}

int main(){
    // build a small demo tree
    //       1
    //      / \
    //     2   3
    //    / 
    //   4
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    cout << "Height of tree: " << height(root) << "\n";

    // cleanup
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

/*
 * Explanation:
 * This algorithm calculates the height of a binary tree using the Hypothesis-Induction-Base Condition method.
 * 1. Base Condition: If the current node is null (empty tree), its height is 0.
 * 2. Hypothesis: We assume the recursive function correctly calculates the height of the left and right subtrees.
 *    We store these values in 'l' and 'r' respectively.
 * 3. Induction: The height of the current tree rooted at this node is the maximum height among its left and
 *    right subtrees, plus 1 (to account for the current node itself).
 */