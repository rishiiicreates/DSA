//max_path_sum but we are restircted to start and end at leaf node;

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

int solve(Node* root, int& result){
    
    if(root == nullptr) return 0;

    int l = solve(root->left, result);
    int r = solve(root->right, result);

    int temp = max(l,r) + root->val;
    if(root->left == nullptr && root->right == nullptr){
        temp = max(temp,root->val);
    }
    int ans = max(temp, l + r + root->val);
    result = max(result, ans);

    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(12);
    root->right->left->right = new Node(2);

        //           1
        //        /     \
        //       2       3
        //     /   \   /   \
        //    4     5 6     7
        //   /         \
        //  12          2

    int result = INT_MIN; // This will hold our final answer
    solve(root, result);

    cout<<"Maximum path sum:"<< result;
    return 0;
}
