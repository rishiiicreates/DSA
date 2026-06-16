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