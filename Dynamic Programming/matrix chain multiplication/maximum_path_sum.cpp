//we have to find the largest summation of node values
//like diameter but we dont have to consider the leaf node, we have to find it from anywhere,
// and we dont have to find largest distance, we have to find the maximum path sum;

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
    
    if(root == nullptr) return 0;

    int l = solve(root->left, result);
    int r = solve(root->right,result);

    int temp = max(max(l,r) + root->data, root->data);
    int ans = max(temp,l + r + root->data); 
    result = max(temp, ans);

    return temp;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(-11);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(12);
    root->right->left->right = new Node(1);

        //           1
        //        /     \
        //       2      -11
        //     /   \   /   \
        //    4     5 6     7
        //   /         \
        //  12          1

    int result = INT_MIN; // This will hold our final answer
    solve(root, result);

    cout<<"Maximum path sum:"<<result;
    return 0;
}