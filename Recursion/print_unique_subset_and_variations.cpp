// also named as powerset/siubsequence/subset
// Flow: Problem statement -> Explanation - Input/output loop -> code variation


// Power set: all subset of a set
// print powerset = print subset

//print subsequence: 

// substring = continuous part of string
// subsequence = parts in continuous order
// subset = parts of string

// LC 78:

#include <iostream>
#include <vector>

using namespace std;

void req_tree(vector<vector<int>>& ans, vector<int> op, vector<int> ip){
    
    //base condition
    if(ip.size() == 0){
        ans.push_back(op);
        return;
    }

    //hypothesis
    vector <int> op1 = op;
    vector <int> op2 = op;
    op2.push_back(ip[0]);

    ip.erase(ip.begin() + 0);

    req_tree( ans, op1, ip);
    req_tree( ans, op2, ip);
}

vector<vector<int>> subset(vector<int>& nums){
    vector <vector<int>> ans;
    vector <int> op = {};
    req_tree(ans, op, nums);

    return ans;
}
int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subset(nums);

    cout << "Subsets:" << endl;
    for (const auto& sub : result) {
        cout << "[ ";
        for (int x : sub) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}
