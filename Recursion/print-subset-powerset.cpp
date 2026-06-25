#include <iostream>
using namespace std;


void solve(string input, string output){
    
    //base condition
    if(input.length() == 0){
        cout<<output<<" ";
        return;
    }

    string op1 = output;
    string op2 = output;

    op2.push_back(input[0]);
    input.erase(input.begin() + 0);

    solve(input,op1);
    solve(input,op2);

    return;
}

int main(){
    string input;
    cin>>input;

    string output = "";
    solve(input,output);
    return 0;
}

/*
 * Explanation:
 * This algorithm recursively generates all subsets (or the powerset) of a given string.
 * It uses the 'include/exclude' decision tree pattern:
 * 1. Base Condition: If the input string is empty, we have completed a subset. Print the 'output' string and return.
 * 2. At each recursive step, we look at the first character of the 'input' string.
 * 3. We create two branches (choices) for the recursive calls:
 *    - op1: Exclude the character (output remains the same).
 *    - op2: Include the character (append it to the output).
 * 4. We remove the first character from the input and recursively call the function for both choices.
 * This effectively explores all possible combinations of characters.
 */